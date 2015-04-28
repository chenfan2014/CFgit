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

using namespace std;

#define MAXLINE 1024
#define PORT 8989
#define IP "127.0.0.1"
#define LISTENMAX 5

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

static void handlerConnection(int *clientfds, int num, fd_set *serverSet, fd_set *clientSet)
{
    int i, n;
    char buffer[MAXLINE];
    memset(buffer, 0, MAXLINE);

    for(i = 0; i != num; i ++){
        if(FD_ISSET(clientfds[i], serverSet)){
            n = recv(clientfds[i], buffer, MAXLINE, 0);
            if(n == 0){
                close(clientfds[i]);
                FD_CLR(clientfds[i], clientSet);
                clientfds[i] = -1;
                continue;
            }


            cout << "Recv message : " << buffer << endl;
            send(clientfds[i], buffer, n, 0);
        }
    }
}

static void doSelect(int serverfd)
{
    int clientfd;
    int i, maxi, maxfd;
    fd_set serverSet, clientSet;
    struct sockaddr_in clientAddr;
    socklen_t clientAddrLen;
    int nready;


    int clientfds[FD_SETSIZE];  //保存客户端链接描述符
    for(i = 0; i != FD_SETSIZE; i ++)
    {
        clientfds[i] = -1;      //初始化客户端连接描述符
    }
    maxi = -1;

    FD_ZERO(&serverSet);
    
    FD_SET(serverfd, &serverSet);
    
    maxfd = serverfd;

    while(1)
    {
        clientSet = serverSet;
        nready = select(maxfd + 1, &clientSet, NULL, NULL, NULL);
        if(nready == -1){
            ERR_EXIT("select error");
        }

        if(FD_ISSET(serverfd, &clientSet)){
            clientAddrLen = sizeof(clientAddr);

            if((clientfd = accept(serverfd, (struct sockaddr *)&clientAddr, &clientAddrLen)) == -1){
                        if(errno == EINTR){
                            continue;
                        }else{
                            ERR_EXIT("accept error");
                        }
            }

            cout << "Client : " << inet_ntoa(clientAddr.sin_addr) << " : " << clientAddr.sin_port << endl;
            
            for(i = 0; i != FD_SETSIZE; i ++){
                if(clientfds[i] == -1){
                    clientfds[i] = clientfd;
                    break;
                }
            }

            if(i == FD_SETSIZE){
                cout << "Too many client here" << endl;
            }

            FD_SET(clientfd, &clientSet);
            maxfd = (clientfd > maxfd ? clientfd : maxfd);
            maxi = (i > maxi ? i : maxi);

            if(--nready == 0){
                continue;
            }
        }
        handlerConnection(clientfds, maxi, &serverSet, &clientSet);
    }

}


int main(int argc, const char *argv[])
{
    struct sockaddr_in serverAddr;
    int serverfd, clientfd;
    int ret;

    if((serverfd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        ERR_EXIT("socket error");
    }

    bzero(&serverAddr, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr(IP);

    if((ret = bind(serverfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr))) == -1){
        ERR_EXIT("bind error");
    }

    if((ret = listen(serverfd, LISTENMAX)) == -1){
        ERR_EXIT("listen error");
    }

    doSelect(serverfd);
    return 0;
}
