#include <iostream>
#include <string>
#include <vector>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8989
#define IPADDRESS "127.0.0.1"
#define MAXSIZE 1024
#define LISTENSIZE 5
#define CONN 2
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)


using namespace std;

void sig_int(int signo)
{
    exit(1);
}

int main(int argc, const char *argv[])
{
    int serverfd;
    int clientfd;
    struct sockaddr_in serverAddr;
    struct sockaddr_in clientAddr;
    char recvStr[MAXSIZE];

    pid_t pidConn[CONN];
    int i = 0;

    signal(SIGINT, sig_int);

    if((serverfd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        ERR_EXIT("socket error");
    }

    bzero(&serverAddr, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr(IPADDRESS);

    if(bind(serverfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1){
        ERR_EXIT("bind error");
    }

    if(listen(serverfd, LISTENSIZE) == -1){
        ERR_EXIT("listen error");
    }

    for(i = 0; i != CONN; i ++){
        if((pidConn[i] = fork()) == 0)
        {
            int n = 0;
            socklen_t clientAddrLen = sizeof(clientAddrLen);
            memset(recvStr, 0, MAXSIZE);
            
            while(1){
                if((clientfd = accept(serverfd, (struct sockaddr *)&clientAddr, &clientAddrLen)) == -1){
                    ERR_EXIT("accept error");
                }

                if((n = recv(clientfd, recvStr, MAXSIZE, 0)) == -1){
                    ERR_EXIT("error recv");
                }

                cout << "Recv : " << recvStr << endl;

                send(clientfd, recvStr, strlen(recvStr), 0);
            }
            close(clientfd);
        }
    }

    close(serverfd);
    return 0;
}

