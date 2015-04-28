#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8888
#define BACKLOG 2

#define ERR_EXIT(m) \
    do{ \
        perror(m);  \
        exit(EXIT_FAILURE); \
    }
int main(int argc, const char *argv[])
{
    int sockfd, clientfd;               //服务器socket描述符和客户端socket描述符
    struct sockaddr_in serverAddr;      //服务器地址结构
    struct sockaddr_in clientAddr;      //客户端地址结构
    int ret;
    pid_t pid;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);   
    if(sockfd == -1){
        ERR_EXIT("server socket error");
    }

    bzero(&serverAddr, sizeof(serverAddr));         //初始化服务器地址结构，#include<string.h>函数，置字符串的前n个值为0
    //memset(&serverAddr, 0, sizeof(serverAddr));   同上面这句相同意思
    serverAddr.sin_family = AF_INET;                //协议族
    serverAddr.sin_port = htons(PORT);              //服务器端口设置，注意字节序的转化
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY); //本地地址

    if((ret  = bind(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr))) < 0){      //绑定到套接字描述符
        ERR_EXIT("sockfd bind error");
    }

    if((ret = listen(sockfd, BACKLOG)) < 0){
        ERR_EXIT("listen error");                   //设置侦听队列，我们设置监听最多为2个
    }

    while(1){
        socklen_t addrLen = sizeof(struct sockaddr);
        
        clientfd = accept(sockfd, (struct sockaddr *)&clientAddr, &addrLen);
        if(clientfd < 0){
            continue;
        }

        if((pid = fork()) < 0){
            ERR_EXIT("fork error");
        }else if(pid == 0){
            close(sockfd);
        }else{
            close(clientfd);
        }
    }

    return 0;
}

void processConnServer(int fd){
    ssize_t size = 0;
    char buffer[1024];

    for(; ; ){
        size = read(fd, buffer, 1024);
        if(size == 0){
            return ;
        }

        sprintf(buffer, "%d bytes altogether\n", size);
        write(fd, buffer, strlen(buffer) + 1);
    }
}
