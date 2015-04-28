#include <iostream>
#include <string>
#include <vector>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <poll.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <time.h>

#define MAXLINE 1024
#define PORT 9999
#define IPADDRESS "127.0.0.1"
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

using namespace std;


static void handlerConnection(int clientfd)
{
    char sendBuf[MAXLINE];
    char recvBuf[MAXLINE];
    struct pollfd pfds[2];
    
    memset(sendBuf, 0, MAXLINE);
    memset(recvBuf, 0, MAXLINE);

    pfds[0].fd = clientfd;
    pfds[0].events = POLLIN;
    pfds[1].fd = STDIN_FILENO;
    pfds[1].events = POLLIN;
    
    while(1)
    {
        poll(pfds, 2, -1);

        if(pfds[0].revents & POLLIN)
        {
            n = recv(clientfd, recvBuf, MAXLINE, 0);
            if(n == 0){
                cerr << "clientfd closed" << endl;
                close(clientfd);
            }

            cout << recvBuf << endl;
        }
        
        if(pfds[1].revents & POLLIN)
        {
            n = read(STDIN_FILENO, sendBuf, MAXLINE);
            if(n == 0){
                shutdown(clientfd, SHUT_WR);
                continue;
            }
            send(clientfd, sendBuf, n, 0);
        }
    }
}

static void handlerConnection(int clientfd){
    int maxfd;
    int n;
    struct pollfd pfds[2];
    

    char sendStr[MAXLINE];
    char recvStr[MAXLINE];

    memset(sendStr, 0, MAXLINE);
    memset(recvStr, 0, MAXLINE);

    pfds[0].fd = clientfd;
    pfds[0].events = POLLIN;

    pfds[1].fd = STDIN_FILENO;
    pfds[1].events = POLLIN;

    while(1)
    {
        poll(pfds, 2, -1);       
        /*
         * int poll(struct pollfd *fds, nfds_t nfds, int timeout);
         * 这里第一个参数是一个指向pollfd结构的指针，第二个参数是比最大描述符值大于1的值
         * 第三个参数表示超时时间，是timeout结构体，当为负数的时候代表永远等待
         *
         */
        
        if(pfds[0].revents & POLLIN)        //检测到这里是从服务器接收到数据
        {
            n = recv(clientfd, recvStr, MAXLINE, 0);
            if(n == 0){
                cout << "serverfd closed " << endl;
                close(clientfd);
            }

            cout << recvStr << endl;
        }

        if(pfds[1].revents & POLLIN)        //检测到我们从屏幕输入
        {
            n = read(STDIN_FILENO, sendStr, MAXLINE);
            if(n == 0){
                shutdown(clientfd, SHUT_WR);
                continue;
            }
            send(clientfd, sendStr, n, 0);
        }
    }

}


int main(int argc, const char *argv[])
{
    struct sockaddr_in clientAddr;
    int clientfd;

    if((clientfd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        ERR_EXIT("socket error");
    }

    bzero(&clientAddr, sizeof(clientAddr));
    clientAddr.sin_port = htons(PORT);
    clientAddr.sin_family = AF_INET;
    clientAddr.sin_addr.s_addr = inet_addr(IPADDRESS);
    
    if((connect(clientfd, (struct sockaddr *)&clientAddr, sizeof(clientAddr))) == -1){
        ERR_EXIT("error connect");
    }
    
    handlerConnection(clientfd);
    
    return 0;
}
