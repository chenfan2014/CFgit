#include <iostream>
#include <string>
#include <vector>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>

#define PORT 8989
#define IPADDRESS "127.0.0.1"
#define BACKLOG 5
#define MAXSIZE 1024
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

using namespace std;

static void handleRequest(int clientfd)
{
    time_t now;
    char buffer[MAXSIZE];
    int n = 0;
    memset(buffer, 0, MAXSIZE);
    n = recv(clientfd, buffer, MAXSIZE, 0);
    cout << "Recv : " << buffer << endl;
    if(n == 0){
        ERR_EXIT("recv error");
    }

    memset(buffer, 0, MAXSIZE);
    now = time(NULL);
    sprintf(buffer, "%24s\r\n", ctime(&now));
    send(clientfd, buffer, strlen(buffer), 0);

    close(clientfd);
}

static int handleConnection(int serverfd)
{
    int clientfd;
    struct sockaddr_in clientAddr;
    socklen_t clientAddrLen = sizeof(clientAddr);

    while(1)
    {
        if((clientfd = accept(serverfd, (struct sockaddr *)&clientAddr, &clientAddrLen)) == -1){
            ERR_EXIT("accept error");
        }

        if(fork() > 0){
            close(clientfd);
        }else{
            handleRequest(clientfd);
            return (0);
        }
    }
}

int main(int argc, const char *argv[])
{
    int serverfd;
    struct sockaddr_in serverAddr;

    if((serverfd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        ERR_EXIT("error socket");
    }

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr(IPADDRESS);

    if(bind(serverfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1){
        ERR_EXIT("bind error");
    }

    if(listen(serverfd, BACKLOG) == -1){
        ERR_EXIT("listen too much client error");
    }

    handleConnection(serverfd);

    close(serverfd);
    return 0;
}

