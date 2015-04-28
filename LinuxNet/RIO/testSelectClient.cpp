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
#include <sys/select.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <time.h>

using namespace std;

#define IPADDRESS "127.0.0.1"
#define MAXLINE 1024
#define PORT 8989

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

int main(int argc, const char *argv[])
{
    int clientfd;
    struct sockaddr_in clientAddr;
    char sendStr[1024] = "";
    char recvStr[1024] = "";
    int maxfd, stdineof;
    fd_set rset;
    int n;

    if((clientfd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        ERR_EXIT("error socket");
    }

    bzero(&clientAddr, sizeof(clientAddr));
    clientAddr.sin_family = AF_INET;
    clientAddr.sin_port = PORT;
    inet_pton(AF_INET, IPADDRESS, &clientAddr.sin_addr);

    if(connect(clientfd, (struct sockaddr *)&clientAddr, sizeof(clientAddr))){
        FD_ZERO(&rset);
        for(;;){
            FD_SET(STDIN_FILENO, &rset);
            FD_SET(clientfd, &rset);

            maxfd = (STDIN_FILENO > clientfd ? STDIN_FILENO : clientfd);
            select(maxfd + 1, &rset, NULL, NULL, NULL);

            if(FD_ISSET(clientfd, &rset)){
                n = read(clientfd, recvStr, MAXLINE);
                if(n == 0){
                    ERR_EXIT("error read");
                    close(clientfd);
                    FD_CLR(clientfd, &rset);
                }

                write(STDOUT_FILENO, recvStr, n);
            }

            if(FD_ISSET(STDIN_FILENO, &rset)){
                n = read(STDIN_FILENO, sendStr, MAXLINE);
                if(n == 0){
                    FD_CLR(STDIN_FILENO, &rset);
                    continue;
                }

                write(clientfd, sendStr, n);
            }

        }
    }
    return 0;
}
