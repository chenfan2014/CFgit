#include <iostream>
#include <string>
#include <vector>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

using namespace std;

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

#define IPFOUND "IP_FOUND"
#define IP_FOUND_ACK "IP_FOUND_ACK"
#define IFNAME "eth0"
#define BUFFERSIZE 32

void IPFound(void *arg)
{
    int ret = -1;
    int sock = -1;
    int soBroadcast = 1;

    struct ifreq ifr;
    struct sockaddr_in broadcastAddr;
    struct sockaddr_in fromAddr;

    int fromAddrLen = sizeof(fromAddr);
    int count = -1;
    fd_set readfd;
    char buffer[BUFFERSIZE];
    
    struct timeval timeout;
    timeout.tv_sec = 2;
    timeout.tv_sec = 0;

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if(sock == -1){
        ERR_EXIT("socket error");
    }

    strcpy(ifr.ifr_name, IFNAME, strlen(IFNAME));
    if(ioctl(sock, SIOCGIFBRDADDR, &ifr) == -1){
        ERR_EXIT("ioctl error");
    }

    memcpy(&broadcastAddr, &ifr.ifr_broadaddr, sizeof(struct sockaddr_in));





}

int main(int argc, const char *argv[])
{
    
    return 0;
}
