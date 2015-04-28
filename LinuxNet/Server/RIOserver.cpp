#include "header.h"
#include <sys/select.h>
#define CLIENTNUM 2

using namespace std;

int connectHost[CLIENTNUM];
int connectNumber = 0;

static void *handleConnect(void *arg)
{
    int serverfd = *((int *)arg);
    int clientfd;
    struct sockaddr_in clientAddr;
    socklen_t clientAddrLen = sizeof(clientAddr);
    
    while(1)
    {
        int i = 0;
        if((clientfd = accept(serverfd, (struct sockaddr *)&clientAddr, &clientAddrLen)) == -1){
            ERR_EXIT("accept error");
        }

        for(i = 0; i != CLIENTNUM; i ++){
            if(connectHost[i] == -1){
                connectHost[i] = clientfd;
                connectNumber ++;
                break;
            }
        }
    }
}

static void *handleRequest(void *arg)
{
    char buffer[MAXSIZES];
    int n = 0;
    int maxfd = -1;
    fd_set scanfd;

    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;

    int i = 0;
    int err = -1;
        
    while(1)
    {
        FD_ZERO(&scanfd);
        for(i = 0; i != CLIENTNUM; i ++)
        {
            if(connectHost[i] != -1)
            {
                FD_SET(connectHost[i], &scanfd);
                if(maxfd < connectHost[i]){
                    maxfd = connectHost[i];
                }
            }
        }

        err = select(maxfd + 1, &scanfd, NULL, NULL, &timeout);

        switch(err)
        {
            case 0:
                break;
            case -1:
                break;
            default:
                for(i = 0; i != CLIENTNUM; i++)
                {
                    if(connectHost[i] != -1)
                    {
                        if(FD_ISSET(connectHost[i], &scanfd))
                        {
                            memset(buffer, 0, MAXSIZES);

                            n = recv(connectHost[i], buffer, MAXSIZES, 0);
                            if(n == -1){
                                ERR_EXIT("recv error");
                            }

                            send(connectHost[i], buffer, strlen(buffer), 0);
                        }

                        connectHost[i] = -1;
                        connectNumber --;
                        close(connectHost[i]);
                    }
                }
                break;
        }
    }
    return NULL;
}

int main(int argc, const char *argv[])
{
    int serverfd;
    struct sockaddr_in serverAddr;
    int i = 0;
        
    if((serverfd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        ERR_EXIT("error socket");
    }

    bzero(&serverAddr, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    inet_pton(AF_INET, IPADDRESS, &serverAddr.sin_addr);

    if(bind(serverfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1){
        ERR_EXIT("bind error");
    }

    if(listen(serverfd, LISTENSIZE) == -1){
        ERR_EXIT("error listen");
    }

    pthread_t thread[2];

    pthread_create(&thread[0], NULL, handleConnect, (void *)&serverfd);     //创建线程处理客户端链接

    pthread_create(&thread[1], NULL, handleRequest, NULL);      //创建线程处理客户端请求

    for(i = 0; i != 2; i ++){
        pthread_join(thread[i], NULL);
    }
    
    close(serverfd);
    return 0;
}
