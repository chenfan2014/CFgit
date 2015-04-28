#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
const int ADDRLEN = 16;

int main(int argc, const char *argv[])
{
    struct in_addr ipAddr;
    char ipString [] = "192.168.1.1";
    char addr[ADDRLEN];

    const char *str = NULL;
    int err = 0;

    if((err = inet_pton(AF_INET, ipString, &ipAddr)) > 0){
        printf("inet_pton : ip = %s, value is 0x%x\n", ipString, ipAddr.s_addr);
    }

    str = (const char *) inet_ntop(AF_INET, (void *)&ipAddr, (char *)&addr[0], ADDRLEN);
    if(str){
        printf("inet_ntop : ip 0x%x, is %s\n", ipAddr.s_addr, str);
    }
    return 0;
}
