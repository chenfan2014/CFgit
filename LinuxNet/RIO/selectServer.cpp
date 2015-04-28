#include <iostream>
#include <string>
#include <vector>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

using namespace std;

#define IP "127.0.0.1"
#define PORT 8989
#define MAXLINE 1024
#define LISTENSIZE 5

#define ERR_EXIT(M) \
    do{ \
        perror(m); \
        exit(EXIT_FAILURE); \
    }while(0)

//IO多路复用select
static void doSelect(int );     

//处理多个连接
static void handlerConnection(int *, int , fd_set *, fd_set *);

int main(int argc, const char *argv[])
{
    struct sockaddr_in serverAddr;
    int serverfd, clientfd;
    int ret;

    if((serverfd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        ERR_EXIT("socket error");
    }
    
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr(IP);

    if((ret = bind(serverfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr))) == -1){
        ERR_EXIT("bind error");
    }

    if(listen(serverfd, LISTENSIZE) == -1){
        ERR_EXIT("listen error");
    }

    doSelect(serverfd);
    return 0;
}


static void doSelect(int serverfd)
{
    int connfd, sockfd;
    struct sockaddr_in clientAddr;
    socklen_t clientAddrLen;
    int maxfd, maxi;
    int clientfds[FD_SETSIZE];
    int nready;
    fd_set allset, rset;

    //初始化客户端描述符
    for(int i = 0; i != FD_SETSIZE; i ++){
        clientfds[i] == -1;
    }

    maxi = -1;

    FD_ZERO(&allset);
    FD_SET(serverfd, &allset);

    maxfd = serverfd;

    while(1)
    {
        rset = allset;
        nready = select(maxfd + 1, &rset, NULL, NULL, NULL);

        if(nready == -1){
            ERR_EXIT("select error");
        }

        if(FD_ISSET(serverfd, &rset))
        {
            clientAddrLen = sizeof(clientAddr);
            
            //建立连接，三次握手机制发生地点
            if((connfd = accept(serverfd, (struct sockaddr *)&clientAddr, &clientAddrLen)) == -1){
                if(errno == EINTR){
                    continue;
                }else{
                    ERR_EXIT("error connect");
                }
            }

            cout << "A new client : " << inet_ntoa(clientAddr.sin_addr) << " : " << clientAddr.sin_port << endl;

            for(int i = 0; i != FD_SETSIZE; i ++)   //将新的连接描述符加入数组中
            {
                if(clientfds[i] < 0){
                    clientfds[i] = connfd;
                    break;
                }
            }

            FD_SET(connfd, &allset);

            maxfd = (connfd > maxfd ? connfd : maxfd);
            

            handlerConnection(clientfds, maxi, &rset, &allset);
        }
    }
}

static void handlerConnection(int *connfds, int num, fd_set *prset, fd_set *pallset)
{
    int i, n;

    char buffer[MAXLINE];
    memset(buffer, 0, MAXLINE);

    for(i = 0; i != num; i ++)
    {
        if(connfds[i] < 0){
            continue;
        }

        if(FD_ISSET(connfds[i], pallset))
        {
            n = recv(connfds[i], buffer, MAXLINE, 0);
            if(n == 0){
                close(connfds[i]);
                FD_CLR(connfds[i], &pallset);
                connfds[i] = -1;
                continue;
            }

            cout << "Recv message is : " << buffer << endl;

            send(connfds[i], buffer, n, 0);
        }
    }
}
