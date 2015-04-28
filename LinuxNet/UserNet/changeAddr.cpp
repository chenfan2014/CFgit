#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
int main(int argc, const char *argv[])
{
    struct in_addr ip, local, network;
    char addr1 [] = "192.168.1.1";
    char addr2 [] = "255.255.255.255";
    char addr3 [] = "192.16.1";
    char *str = NULL;
    char *str2 = NULL;
    
    int err = 0;
    err = inet_aton(addr1, &ip);        //点分十进制字符串类型IP转变成二进制IP地址，成功返回非0，失败返回0
    /*
     * 这里我们返回的是一个in_addr的数据结构，然后通过输出in_addr的数据结构中的s_addr
     * 参数，这个参数就是我们的ip地址
     */
    if(err){
        printf("inet_aton : string %s value is 0x%x", addr1, ip.s_addr);
    }else{
        printf("inet_addr : string %s error\n", addr1);
    }
    
    ip.s_addr = inet_addr(addr1);       //inet_addr这里返回的是我们的二进制IP地址
    if(err != -1){
        printf("inet_addr : string %s value is 0x%x\n", addr1, ip.s_addr);
    }else{
        printf("inet_addr : string %s value error \n", addr1);
    }
    ip.s_addr = inet_addr(addr2);
    if(ip.s_addr != -1){
        printf("inet_addr : string %s value is : 0x%x \n", addr2, ip.s_addr);
    }else{
        printf("inet_addr : string %s error\n", addr2);
    }
    
    
    
    return 0;
}
