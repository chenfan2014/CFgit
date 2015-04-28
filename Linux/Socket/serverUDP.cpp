#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>
using namespace std;

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

int main(int argc, const char *argv[])
{
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sockfd == -1){
        ERR_EXIT("socket error");
    }
    
    if(argc != 3){
        ERR_EXIT("too few args");
    }

    struct sockaddr_in serverAddr;
    //bzero(&serverAddr, sizeof(serverAddr));
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(atoi(argv[2]));
    serverAddr.sin_addr.s_addr = inet_addr(argv[1]);
    
    if(bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(struct sockaddr)) == -1){
        close(sockfd);
        ERR_EXIT("bind error");
    }
   
    char buf[1024] = " ";
   
    while(1){
        struct sockaddr_in clientAddr;
        socklen_t clientLen = sizeof(struct sockaddr);
        memset(&clientAddr, 0, sizeof(clientAddr));
        
        
        if(recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr*)&clientAddr, &clientLen) == -1){
            close(sockfd);
            ERR_EXIT("error recvfrom");
        }
        cout << "Recv : " << buf << endl;
        
        char send[] = "success\n";
        if(sendto(sockfd, send, sizeof(send), 0, (struct sockaddr*)&clientAddr, clientLen) == -1){
            close(sockfd);
            ERR_EXIT("error sendto");
        }
    }
    close(sockfd);
    return 0;
}
