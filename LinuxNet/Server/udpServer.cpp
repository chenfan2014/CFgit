#include <iostream>
#include <string>
#include <vector>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

using namespace std;

#define PORT 8989
#define IPADDRESS "127.0.0.1"
#define MAXSIZE 1024
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

int main(int argc, const char *argv[])
{
    struct sockaddr_in serverAddr;
    int serverfd;
    char recvStr[MAXSIZE];

    if((serverfd = socket(AF_INET, SOCK_DGRAM, 0)) == 0){
        ERR_EXIT("socket error");
    }

    bzero(&serverAddr, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr(IPADDRESS);

    if(bind(serverfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1){
        ERR_EXIT("bind error");
    }
    
    while(1)
    {
        memset(recvStr, 0, MAXSIZE);
        struct sockaddr_in clientAddr;
        socklen_t clientAddrLen = sizeof(clientAddr);

        cout << "Client : " << inet_ntoa(clientAddr.sin_addr) << " : " << clientAddr.sin_port << endl;

        int n = recvfrom(serverfd, recvStr, MAXSIZE, 0, (struct sockaddr *)&clientAddr, &clientAddrLen);
        if(n == -1){
            ERR_EXIT("recvfrom error");
        }

        cout << "Recv from : " << recvStr << endl;
        sendto(serverfd, recvStr, strlen(recvStr), 0, (struct sockaddr *)&clientAddr, sizeof(clientAddr));
    }
    close(serverfd);
    return 0;
}
