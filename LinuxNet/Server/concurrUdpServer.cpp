#include <iostream>
#include <string>
#include <vector>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <error.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <signal.h>
using namespace std;
#define IPADDRESS "127.0.0.1"
#define PORT 8989
#define MAXSIZE 1024
#define PIDNUMB 2
#define BACKLOG 5
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

static void handleConnect(int serverfd)
{
    struct sockaddr_in from;

    socklen_t fromLen = sizeof(from);
    int n = 0;
    char buffer[MAXSIZE];

    while(1)
    {
        memset(buffer, 0, MAXSIZE);
        
        n = recvfrom(serverfd, buffer, MAXSIZE, 0, (struct sockaddr *)&from, &fromLen);
        if(n == 0){
            ERR_EXIT("error recvfrom");
        }

        cout << "Recvfrom : " << buffer << endl;
        sendto(serverfd, buffer, strlen(buffer), 0, (struct sockaddr *)&from, fromLen);
    }
}

void sig_int(int num)
{
    exit(1);
}

int main(int argc, const char *argv[])
{
    int serverfd;
    struct sockaddr_in serverAddr;
    char recvStr[MAXSIZE];
    char sendStr[MAXSIZE];
    
    signal(SIGINT, sig_int);        //信号处理函数

    if((serverfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1){
        ERR_EXIT("socket error");
    }

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr(IPADDRESS);

    if(bind(serverfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1){
        ERR_EXIT("bind error");
    }

    pid_t pid[PIDNUMB];
    int i = 0;
    for(i = 0; i != PIDNUMB; i ++){
        pid[i] = fork();
        if(pid[i] == 0){
            struct sockaddr_in clientAddr;
            socklen_t clientAddrLen;
            int n;
            memset(recvStr, 0, MAXSIZE);
            memset(sendStr, 0, MAXSIZE);

            while(1)
            {
                n = recvfrom(serverfd, recvStr, MAXSIZE, 0, (struct sockaddr *)&clientAddr, &clientAddrLen);
                if(n == -1){
                    ERR_EXIT("recvfrom error");
                }

                cout << "Recv from : " << recvStr << endl;
                sendto(serverfd, recvStr, strlen(recvStr), 0, (struct sockaddr *)&clientAddr, clientAddrLen);
            }
        }
    }
    while(1);
    return 0;
}

