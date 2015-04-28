#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <signal.h>

using namespace std;

#define ERR_EXIT(m) \
    do{ \
        perror(m);  \
        exit(0);    \
    }while(1)

const int port = 8080;
const char *ip = "127.0.0.1";

void signalHandler(void){
    sigset_t sigSet;
    sigemptyset(&sigSet);
    sigaddset(&sigSet, SIGINT);
    sigaddset(&sigSet, SIGQUIT);
    sigprocmask(SIG_BLOCK, &sigSet, NULL);
}

int main(int argc, const char *argv[])
{
    signalHandler();
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1){
        ERR_EXIT("error socket");
    }
    
    int resue = 1;
    if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (const char*)&resue, sizeof(int)) < 0){
        ERR_EXIT("error setsockopt");
    }


    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(struct sockaddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = inet_addr(ip);

    if(bind(sockfd, (struct sockaddr *)&serverAddr, sizeof(struct sockaddr)) == -1){
        //将socket和制定的ip和端口绑定
        close(sockfd);
        ERR_EXIT("error bind");
    }

    if(listen(sockfd, 10) == -1){   //监听sockfd，最大的监听数目是10
        close(sockfd);
        ERR_EXIT("error listen");
    }


    struct sockaddr_in clientAddr;
    memset(&clientAddr, 0, sizeof(struct sockaddr));
    socklen_t addrLen = sizeof(struct sockaddr);
    int clientfd = accept(sockfd, (struct sockaddr*)&clientAddr, &addrLen);
    if(clientfd == -1){
        close(sockfd);
        ERR_EXIT("error accept");
    } 

    cout << inet_ntoa(clientAddr.sin_addr) << " " << ntohs(clientAddr.sin_port) << "success connect " << endl;
    //printf("%s %d success connect...\n",inet_ntoa(clientaddr.sin_addr),ntohs(clientaddr.sin_port));

    char buf[1024];
    memset(buf, 0, 1024);
    while(1){
        if(recv(clientfd, buf, sizeof(buf), 0) == -1){
            close(sockfd);
            close(clientfd);
            ERR_EXIT("error recv");
        }
        cout << "Recv : " <<buf << endl;

        char sendBuf[] = "Success recv\n";
        if(send(clientfd, sendBuf, sizeof(sendBuf), 0) == -1){
            close(sockfd);
            close(clientfd);
            ERR_EXIT("error send");
        }
        cout << "Success send back " << endl;
    }
    close(clientfd);
    close(sockfd);
    return 0;
}
