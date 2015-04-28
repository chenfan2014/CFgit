#include <iostream>
#include <string>
#include <vector>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>

using namespace std;

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

/* 
 * 进程间传递文件描述符
 * 进程A中打开一个文件描述符
 * 通过消息传送的方式将文件描述符传递给B
 */

/* 
 * 进程A通过用户输入的文件名打开一个文件
 * 将文件描述符打包到消息结构中
 * 然后发送给进程 B
 */

/*
 * 函数send_fd向文件描述符fd发送消息，将sendfd打包到消息体当中
 */

//send_fd(atoi(argv[1]), "", 1, fd)
ssize_t send_fd(int fd, void *data, size_t bytes, int sendfd)
{
    struct msghdr msghdrSend;                       //建立一个消息，之后填充此消息的成员数据，并发送给fd
    struct iovec iov[1];                            //行为向量，消息数据在此项中两种保存

    //建立一个了联合结构，方便操作msg的结构
    union{
        struct cmsghdr cm;                          //control msg结构
        char control[CMSG_SPACE(sizeof(int))];      //字符指针，方便控制
    }control_un;

    struct cmsghdr *pcmsghdr = NULL;                //控制头部的指针
    msghdr_send.msg_control = control_un.control;   //控制消息
    msghdr_send.msg_controllen = sizeof(control_un.control);    //长度

    pcmsghdr = CMSG_FIRSTHDR(&msghdr_send);         //取得消息的第一个头部
    pcmsghdr -> cmsg_len = CMSG_LEN(sizeof(int));
    pcmsghdr -> cmsg_level = SOL_SOCKET;            //用于控制消息
    pcmsghdr -> cmsg_type = SCM_RIGHTS;             //
    *((int *)CMSG_DATA(pcmsghdr)) = sendfd;         //socket值

    //将消息的名称和长度置空
    msghdr_send.msg_name = NULL;    //名称
    msghdr_send.msg_namelen = 0;    //名称长度

    iov[0].iov_base = data;         //将传入的数据和长度传递给向量成员
    iov[0].iov_len = bytes;
    msghdr_send.msg_iov = iov;      //向向量填充消息
    msghdr_send.msg_iovlen = 1;     //设置向量的个数

    return (sendmsg(fd, &msghdr_send, 0));  //发送消息给fd
}

int main(int argc, const char *argv[])
{
    int fd;
    ssize_t n;
    
    if(argc != 4){
        ERR_EXIT("too few args");
    }

    if((fd = open(argv[2], atoi(argv[3]))) < 0){        //打开输入文件的名称
        return 0;
    }

    if((n = send_fd(atoi(argv[1], "", 1, fd))) < 0){    //发送文件描述符
       return 0;
    }
    return 0;
}

