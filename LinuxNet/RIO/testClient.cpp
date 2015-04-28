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

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

#define IPADDRESS "127.0.0.1"
#define PORT 8989


int main(int argc, const char *argv[])
{
    struct sockaddr_in clientAddr;
    int clientfd;
    socklen_t clientAddrLen;
    int ret;
    char sendStr[1024] = " ";
    if((clientfd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        ERR_EXIT("error socket");
    }

    bzero(&clientAddr, sizeof(clientAddr));
    clientAddr.sin_family = AF_INET;
    clientAddr.sin_port = htons(PORT);
    clientAddr.sin_addr.s_addr = inet_addr(IPADDRESS);

    if(connect(clientfd, (struct sockaddr *)&clientAddr, sizeof(clientAddr)) == -1){
        ERR_EXIT("connect error");
    }
    
    while(1){
        int n;
        memset(sendStr, 0, 1024);

        n = read(STDIN_FILENO, sendStr, 1024);
        if(send(clientfd, sendStr, n, 0) < 0){
            ERR_EXIT("send error");
        }
        if(recv(clientfd, sendStr, n, 0) < 0){
            ERR_EXIT("error recv");
        }
        cout << sendStr << endl;
        //write(clientfd, sendStr, strlen(sendStr));
    }
    close(clientfd);
    return 0;
}
