#include <iostream>
#include <string>
#include <vector>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/select.h>

using namespace std;

#define IPFOUND "IP_FOUND"
#define IPFOUNDACK "IP_FOUND_ACK"
#define BUFFERSIZE 32
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)
void handleIPFound(void *arg)
{
    int ret = -1;
    SOCKET sock = -1;
    struct sockaddr_in localAddr;           //客户端地址
    struct sockaddr_in fromAddr;            //本地地址
    int fromAddrLen = sizeof(fromAddr);
    int count = -1;
    fd_set readfd;
    char buffer[BUFFERSIZE];
    struct timeval timeout;

    timeout.tv_sec = 2;
    timeout.tv_usec = 0;

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if(sock == -1){
        ERR_EXIT("error socket");
    }

    memset(&localAddr, 0, sizeof(localAddr));
    localAddr.sin_family = AF_INET;
    localAddr.sin_port = htons(MCAST_PORT);
    localAddr.sin_addr.s_addr = htonl(INADDR_ANY);

    if((ret = bind(sock, (struct sockaddr *)&localAddr, sizeof(localAddr))) == -1){
        ERR_EXIT("bind error");
    }

    while(1)
    {
        FD_ZERO(&readfd);
        FD_SET(sock, &readfd);

        ret = selectsocket(sock + 1, &readfd, NULL, NULL, &timeout);
        switch(ret){
            case -1:
                break;
            case 0:
                cout << "Over time " << endl;
            default:
                if(FD_ISSET(sock, &readfd)){
                    count = recvfrom(sock, buffer, MAXLEN, 0, (struct sockaddr *)&fromAddr, &fromAddrLen);
                    cout << "Recv from : " << buffer << endl;
                    if(strstr(buffer, IP_FOUND))
                    {
                        memcpy(buffer, IP_FOUND_ACK, strlen(IP_FOUND_ACK) + 1);
                        count = sendto(sock, buffer, strlen(buffer), 0, (struct sockaddr*)&fromAddr, sizeof(fromAddr));
                        
                    }
                }
        }
    }
    cout << "HANDLE IP FOUND" << endl;
    return 0;
}

int main(int argc, const char *argv[])
{
    
    return 0;
}
