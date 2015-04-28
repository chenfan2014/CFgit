#include <iostream>
#include <string>
#include <vector>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>
#include <signal.h>

using namespace std;

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

#define IP "127.0.0.1"
#define PORT 8989
#define MAXLINE 1024

static void handlerConnection(int clientfd)
{
    char sendStr[1024], recvStr[1024];
    fd_set clientSet;
    int maxfd;
    int n;

    memset(sendStr, 0, 1024);
    memset(recvStr, 0, 1024);
    
    FD_ZERO(&clientSet);
    
    while(1)
    {
        FD_SET(STDIN_FILENO, &clientSet);
        FD_SET(clientfd, &clientSet);

        maxfd = (STDIN_FILENO > clientfd ? STDIN_FILENO : clientfd);
        select(maxfd + 1, &clientSet, NULL, NULL, NULL);

        if(FD_ISSET(STDIN_FILENO, &clientSet))
        {
          n = read(STDIN_FILENO, sendStr, 1024);
          if(n == 0)
          {
            FD_CLR(STDIN_FILENO, &clientSet);
            continue;
          }

          send(clientfd, sendStr, n, 0);
        }

        if(FD_ISSET(clientfd, &clientSet))
        {
            n = recv(clientfd, recvStr, 1024, 0);
            if(n == 0)
            {
                cerr << "server is closed" << endl;
                close(clientfd);
                FD_CLR(clientfd, &clientSet);
            }

            cout << recvStr << endl;
        }
    }
}

int main(int argc, const char *argv[])
{
    struct sockaddr_in clientAddr;
    int clientfd;
    socklen_t clientAddrLen;

    if((clientfd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        ERR_EXIT("socket error");
    }

   bzero(&clientAddr, sizeof(clientAddr));
   clientAddr.sin_family = AF_INET;
   clientAddr.sin_port = htons(PORT);
   clientAddr.sin_addr.s_addr = inet_addr(IP);
    
   clientAddrLen = sizeof(clientAddr);
   if(connect(clientfd, (struct sockaddr *)&clientAddr, clientAddrLen) == -1){
    ERR_EXIT("connect error");
   }

    handlerConnection(clientfd);

    return 0;
}


