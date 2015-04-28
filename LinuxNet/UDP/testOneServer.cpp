#include <iostream>
#include <string>
#include <vector>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>

using namespace std;

#define IPADDRESS "127.0.0.1"
#define PORT 8989
#define MAXSIZE 1024

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

int main(int argc, const char *argv[])
{
    int serverfd;
    struct sockaddr_in serverAddr;
    socklen_t serverAddrLen;
    char recvStr[MAXSIZE];

    if((serverfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1){
        ERR_EXIT("socket error");
    }

    bzero(&serverAddr, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr(IPADDRESS);

    if(bind(serverfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1){
        ERR_EXIT("bind error");
    }
    
    serverAddrLen = sizeof(serverAddr);

    while(1)
    {
        int n = 0;
        memset(recvStr, 0, MAXSIZE);
        n = recvfrom(serverfd, recvStr, MAXSIZE, 0, (struct sockaddr *)&serverAddr, &serverAddrLen);
        if(n == -1){
            ERR_EXIT("recvfrom error");
        }else if(n == 0){
            cout << "client closed" << endl;
        }
        
        cout << "Recv message : " << recvStr << endl;

        sendto(serverfd, recvStr, strlen(recvStr), 0, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
    }
    return 0;
}
