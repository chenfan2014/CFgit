#include <string.h>   //bzero
#include <stdlib.h>
#include <stdio.h>

#include <iostream>
#include <string>
#include <vector>

#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <signal.h>
#include <sys/time.h>
#include <errno.h>
#include <netdb.h>
#include <pthread.h>

using namespace std;

/*
 * CRC16校验和计算
 * 参数:    data(数据), len(数据长度)
 * 返回值:  计算结果(short 类型)
 */
static unsigned short icmpCksum(unsigned char *data, int len)
{
    int sum = 0;                //计算结果
    int odd = len & 0x01;       //判断是否为奇数,0则为偶数长度,否则为奇数长度

    /*将数据按照两个字节为单位累加起来*/
    while(len & 0xfffe)
    {
        sum += *(unsigned short *)data;
        data += 2;
        len -= 2;
    }

    if(odd){     //如果是奇数位,那么还要进入这步进行处理
        unsigned short tmp = ((*data) << 8) & 0xff00;
        sum += tmp;
    }

    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);

    return ~sum;
}

/*
 * 设置ICMP发送报文的头部
 * 首先建立icmp报文的结构,然后再设置报头
 */
struct icmp{
    u_int8_t icmp_type;         //icmp类型
    u_int8_t icmp_code;         //icmp代码
    u_int8_t icmp_cksum;        //icmp校验和
    union{
        struct ih_idseq{            //ping 的数据结构
            u_int16_t icd_id;       //数据报ID,标识符
            u_int16_t icd_seq;      //序列号
        }ih_idseq;
    }icmp_hun;
#define icmp_id icmp_hun.ih_idseq.icd_id        //简化union中的两个数据结构
#define icmp_seq icmp_hun.ih_idseq.icd_seq
    union{                          //数据部分
        u_int8_t id_data[1];
    }icmp_dun;
#define icmp_data icmp_dun.id_data
};

/*设置ICMP报头*/
static void icmp_pack(struct icmp *icmph, int seq, struct timeval *tv, int length)
{
    unsigned char i = 0;

    /*设置报头开始*/
    icmph -> icmp_type = ICMP_ECHO;     //ICMP回显请求.类型0,代码是0
    icmph -> icmp_code = 0;             //代码值为0,
    icmph -> icmp_cksum = 0;            //先将cksum值填写0, 便于之后的cksum的计算
    icmph -> icmp_seq = seq;
    icmph -> icmp_id = pid & 0xffff;    //填写PID

    for(i = 0; i != length; i ++)
    {
        icmph -> icmp_data[i] = i;
    }

    icmph -> icmp_cksum = icmpCksum((unsigned char *)icmph, length);
}

/*剥离ICMP接收报文的头部,分析ICMP头部的值,判断是否为正确的ICMP报文,并且打印结果*/
static int icmp_upack(char *buf, int len)
{
    int i, iphdrlen;
    struct ip *ip = NULL;
    struct icmp *icmp = NULL;
    int rtt;

    ip = (struct ip *)buf;              //ip头部
    iphdrlen = ip -> ip_hl * 4;         //ip头部长度
    icmp = (struct icmp *)(buf + iphdrlen);     //ICMP段的地址
    len -= iphdrlen;

    if(len < 8){            //判断长度是否为ICMP包,
        cout << "ICMP packets length is less than 8" << endl;
        return -1;
    }

    //ICMP类型为ICMP_ECHOREPLY并且为本进程ID
    if((icmp -> icmp_type == ICMP_ECHOREPLY) && (icmp -> icmp_id == pid)){
        struct timeval tv_internel, tv_recv, tv_send;

        pingm_packet *packet = icmp_findpacket(icmp -> icmp_seq);   //在发送表格中查找已经发送的包,按照seq
        if(packet == NULL){
            return -1;
        }

        packet -> flag = 0;                 //取消标志
        tv_send = packet -> tv_begin;       //获取本包发送时间
    
        gettimeofday(&tv_recv, NULL);       //读取此时时间,用来计算时间差

        tv_internel = icmp_tvsub(tv_recv, tv_send);
        rtt = tv_internel.tv_sec * 1000 + tv_internel.tv_usec/1000;

        //打印结果,包含ICMP段长度,源IP地址,包的序列号,TTL,时间差
        printf("%d byte from %s : icmp_seq = %u ttl = %d rtt = %d ms\n", len, inet_ntoa(ip -> ip_src, icmp -> icmp_seq, ip -> ip_ttl, rtt));

        packet_recv ++;
    }else{
        return -1;
    }
}

/* 
 * 由于我们需要估算网络状况,在发送报文的时候记录发送时间,然后接收到以后记录接收时刻,两个时刻之间的差值time_sub
 * 生成了ICMP源主机和目标主机之间的网络状况时间评估
 * 参数:  end:接收到的时间,  begin:开始发送的时间   返回时间差
 */
static struct timeval icmp_tvsub(struct timeval end, struct timeval begin)
{
    struct timeval tv;

    tv.tv_sec = end.tv_sec - begin.tv_sec;
    tv.tv_usec = end.tv_usec - begin.tv_usec;

    if(tv.tv_usec < 0){
        tv.tv_sec --;
        tv.tv_usec += 1000000;
    }

    return tv;
}

/* 
 * 发送报文函数是一个线程,每隔1s向目标主机发送一个ICMP回显请求报文,
 * 他在整个程序中处于激活状态的时候一直发送报文
 */
static void *icmp_send(void *argv)
{
    gettimeofday(&tv_begin, NULL);      //保存程序开始发送数据的时间
    while(alive)    //这个意味着程序处理激活状态
    {
        int size = 0;
        struct timeval tv;
        gettimeofday(&tv, NULL);        //当前包的发送时间

        pingm_packet *packet = icmp_findpacket(-1);     //在发送包状态数据中找一个空闲位置
        if(packet){
            packet -> seq = packet_send;
            packet -> flag = 1;                         //设置标记为已经使用
            gettimeofday(&packet -> tv_begin, NULL);     //发送时间
        }

        icmp_pack((struct icmp *)send_buff, packet_send, &tv, 64);

        size = sendto(rawsock, send_buff, 64, 0, (struct sockaddr *)&dest, sizeof(dest));
        if(size == 0){
            perror("sendto error");
            continue;
        }

        packet_send ++;

        sleep(1);   //每隔1s,发送一个ICMP回显请求包
    }
}


/* 
 * 接收报文,同样用一个线程来实现,使用select轮训等待报文
 * 当接收到一个报文的时候,使用函数icmp_unpack()来解包
 * 和查找报文之前发送的时候的记录
 * 获取发送时间,计算首发差值并且打印信息
 */

static void *icmp_recv(void *argv)
{
    //轮训等待时间
    struct timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = 200;

    fd_set readfd;

    while(alive)
    {
        int ret = 0;
        FD_ZERO(&readfd);
        FD_SET(rawsock, &readfd);
        ret = select(rawsock + 1, &readfd, NULL, NULL, &tv);
        switch(ret)
        {
            case -1:    //除错
                break;
            case 0:     //超时
                break;
            default:
                {
                    //收到一个包
                    int fromlen = 0;
                    struct sockaddr from;

                    int size = recv(rawsock, recv_buff, sizeof(recv_buff));
                    if(errno == EINTR){
                        perror("errr recvfrom");
                        continue;
                    }

                    ret = icmp_unpack(recv_buff, size);
                    if(ret == -1){
                        continue;
                    }
                }
                break;
        }
    }
}

typedef struct pingm_packet{        //保存已经发送包的状态值
    struct timeval tv_begin;        //发送时间
    struct timeval tv_end;          //接收到的时间 
    short seq;                      //序列号
    int flag;                       //1表示已经发送但是没有接收到回应,0表示接收到回应
}pingm_packet;
static pingm_packet pingpacket[128];

//信号处理函数
static void icmp_sigint(int signo)
{
    alive = 0;
    gettimeofday(&tv_end, NULL);
    tv_internel = icmp_tvsub(tv_end, tv_begin);

    return ;
}


/* 函数icmp_findpacket()用于在数组pingpacket中查找一个报文的标识
 * 参数为-1的时候表示查找一个空包,
 * 存放已经发送成功的报文,其他值表示查找seq匹配的标识
 */
static pingm_packet *icmp_findpacket(int seq)
{
    int i = 0;
    pingm_packet *found = NULL;

    if(seq == -1){
        for(i = 0; i != 128; i ++){
            if(pingpacket[i].flag == 0){
                found = &pingpacket[i];
                break;
            }
        }
    }else if(seq >= 0){
        for(i = 0; i != 128; i ++){
            if(pingpacket[i].seq == seq){
                found = &pingpacket[i];
                break;
            }
        }
    }

    return found;
}

/* 统计数据结果函数icmp_statistics()用于统计总体的结果
 * 包含发送成功的报文数量,成功接收的数量,丢失百分比
 * 以及总共程序运行时间等等
 */

static void icmp_statistics(void)
{
    long time(tv_internel.tv_sec * 1000) + (tv_internel.tv_usec / 1000);
    printf("---- %s ping statistics ----\n", dest_str);
    printf("%d packets transmitted, %d received , %d%c packetloss, time %d ms \n", packet_send, packet_recv, (packet_send - packet_recv) * 100 / packet_send, '%', time);

}

int main(int argc, const char *argv[])
{
    printf("ping www.baidu.com\n");
    return 0;
}
