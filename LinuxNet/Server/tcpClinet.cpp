#include <iostream>
#include <string>
#include <vector>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>

#define PORT 8989
#define IPADDRESS "127.0.0.1"
#define MAXSIZE 1024
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

using namespace std;

int main(int argc, const char *argv[])
{
    int clientfd;
    struct sockaddr_in clientAddr;
    char sendStr[MAXSIZE];
    char recvStr[MAXSIZE];

    socklen_t clientAddrLen = sizeof(clientAddrLen);

    if((clientfd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        ERR_EXIT("socket error");
    }

    bzero(&clientAddr, sizeof(clientAddr));
    clientAddr.sin_family = AF_INET;
    clientAddr.sin_port = htons(PORT);
    clientAddr.sin_addr.s_addr = inet_addr(IPADDRESS);

    if(connect(clientfd, (struct sockaddr *)&clientAddr, sizeof(clientAddr)) == -1){
        ERR_EXIT("error conn");
    }
    
    while(1)
    {
        memset(recvStr, 0, MAXSIZE);
        memset(sendStr, 0, MAXSIZE);

        int n = read(STDIN_FILENO, sendStr, MAXSIZE);
        if(n == -1){
            ERR_EXIT("read error");
        }

        if(send(clientfd, sendStr, n, 0) == -1){
            ERR_EXIT("send error");
        }

        if(recv(clientfd, recvStr, MAXSIZE, 0) == -1){
            ERR_EXIT("recv error");
        }
        cout << "Recv from Server : " << recvStr << endl;
    }
    
    
    return 0;
}

