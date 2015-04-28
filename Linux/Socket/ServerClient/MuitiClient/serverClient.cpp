#include "socketHead.h"
#include <fcntl.h>
using namespace std;

void signalHandler(void)
{
    sigset_t sigSet;
    sigemptyset(&sigSet);
    sigaddset(&sigSet, SIGINT);
    //sigaddset(&sigSet, SIGQUIT);
    sigprocmask(SIG_BLOCK, &sigSet, NULL);
}

int socketInit(int port, const char *ip)
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1){
        ERR_EXIT("socket error");
    }
    int flags = fcntl(sockfd, F_GETFL, 0);
　　fcntl(sockfd,F_SETFL,O_NONBLOCK | iflags);

    int ret = 1;
    if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (const char *)&ret, sizeof(int)) < 0){
        ERR_EXIT("setsockopt error");
    }

    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(struct sockaddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = inet_addr(ip);

    

    if(bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(struct sockaddr)) == -1){
        ERR_EXIT("bind error");
    }
    return sockfd;
}

int serverListenAccept(int sockfd)
{
    if(listen(sockfd, 10) == -1){
        ERR_EXIT("listen error");
    }

    struct sockaddr_in clientAddr;
    memset(&clientAddr, 0, sizeof(clientAddr));
    socklen_t len = sizeof(struct sockaddr);
    int clientfd;
    if((clientfd = accept(sockfd, (struct sockaddr*)&clientAddr, &len)) == -1){
        ERR_EXIT("accept error");
    }
    
    cout << "Clinet " << inet_ntoa(clientAddr.sin_addr) << " Connect success" << endl;
    return clientfd;
}

void serverMessage(int sockfd, int clientfd)
{
    char serverBuf[1024];
    memset(serverBuf, 0, 1024);

    while(1){
        if(recv(clientfd, serverBuf, 1024, 0) == -1){
            close(clientfd);
            close(sockfd);
            ERR_EXIT("error recv");
        }
        cout << "Recv Success " << serverBuf << endl;
        strcpy(serverBuf, "Good job\n");
        if(send(clientfd, serverBuf, sizeof(serverBuf), 0) == -1){
            close(clientfd);
            close(sockfd);
            ERR_EXIT("send error");
        }
        cout << "Send back success" << endl;
    }
    close(clientfd);
}

int clientConnect(int port, const char *ip)
{
    int clientfd = socket(AF_INET, SOCK_STREAM, 0);
    if(clientfd == -1){
        ERR_EXIT("socket error");
    }

    struct sockaddr_in clientAddr;
    memset(&clientAddr, 0, sizeof(struct sockaddr));
    clientAddr.sin_family = AF_INET;
    clientAddr.sin_port = htons(port);
    clientAddr.sin_addr.s_addr = inet_addr(ip);

    if(connect(clientfd, (struct sockaddr*)&clientAddr, sizeof(struct sockaddr)) == -1){
        ERR_EXIT("connect error");
    }
    cout << "Connect " << ip << "  Success" << endl;
    return clientfd;
}

void clientMessage(int clientfd)
{
    char clientBuf[1024];
    memset(clientBuf, 0, 1024);
    while(1){
        char sendStr[1024];
        cin >> sendStr;
        if(send(clientfd, sendStr, strlen(sendStr), 0) == -1){
            close(clientfd);
            ERR_EXIT("send error");
        }
        cout << "Send " << sendStr << " Success" << endl;
        
        if(recv(clientfd, clientBuf, 1024, 0) == -1){
            close(clientfd);
            ERR_EXIT("recv error");
        }
        cout << "Recv Message " << clientBuf << endl;
    }
}
