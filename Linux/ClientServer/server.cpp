#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <errno.h>

#include <netinet.h>
#include <sys/stat.h>
#include <sys/socket/h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/time.h>
using namespace std;

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

const string IPADDRESS = "127.0.0.1";
const int PORT = 8888;
const int MAXLINE = 1024;
const int LISTENQ = 5;

static int socketBind(const string &s, int port)
{
    int listenFd;
    struct sockaddr_in serverAddr;
    listenFd = socket(AF_INET, SOCK_STREAM, 0);
    if(listenFd == -1){
        ERR_EXIT("socket error listenfd");
    }
    bzero(&serverAddr, sizeof serverAddr); 
    serverAddr.sin_family = AF_INET;
    inet_pont(AF_INET, ip, &serverAddr.sin_addr);
    serverAddr.sin_port = htons(port);
    if(bind(listenFd, (struct sockaddr *)&serverAddr, sizeof serverAddr) == -1){
        ERR_EXIT("bind error");
    }
    
    return listenFd;

}

static void doSelect(int listenFd)
{
    int connFd, sockFd;
    struct sockaddr_in clientAddr;
    socklen_t clientAddrLen;
    fd_set rSet, allSet;
    int maxFd, maxI;
    int i;
    int clientFds[FD_SETSIZE];
    int nReady;
    for(i = 0; i < FD_SETSIZE; i ++){
        clientFds[i] = -1;
    }

    maxI = -1;
    FD_ZERO(&allSet);
    FD_SET(listenFd, &allSet);
    maxFd = listenFd;
    for(; ; ){
        rSet = allSet;
        nReady = select(maxFd + 1, &rSet, NULL, NULL, NULL);
        if(nReady == -1){
            ERR_EXIT("select error");
        }

        if(FD_ISSET(listenFd, &rSet)){
            clientAddrLen = sizeof clientAddr;
            if((connFd = accept(listenFd, (struct sockaddr *)&clientAddr, &clientAddrLen)) == -1){
                if(errno == EINTR){
                    continue;
                }else{
                    ERR_EXIT("accept error");
                }
            }

            fprintf(stdout, "accpet a new client : %s : %d\n", inet_ntoa(clientAddr.sin_addr), clientAddr.sin_port);

            for (int i = 0; i < FD_SETSIZE; i++) {
                if(clientFds[i] < 0){
                    clientFds[i] = connFd;
                    break;
                }
            }

            if(i == FD_SETSIZE){
                fprintf(stderr, "too many client\n");
            }

            FD_SET(connFd, &allSet);
            maxFd = (connFd > maxFd ? connFd : maxFd);
            maxI = (i > maxI ? i : maxI);
            if(-- nReady <= 0){
                continue;
            }
        }
        handlerConnection(clientFds, maxI, &rSet, &allSet);
    }

}

static void handlerConnection(int *connFds, int num, fd_set *prSet, fd_set *pallSet){
    int i, n;
    string buf = " ";
    for (i = 0; i <= num; i++) {
        if(connFds[i] < 0){
            continue;
        }

        if(FD_ISSET(connFds[i], prSet)){
            n = read(connFds[i], buf.c_str(), MAXLINE);
        }
        if(n == 0){
            close(connFds[i]);
            FD_CLR(connFds[i], pallSet);
            connFds[i] = -1;
            continue;
        }
        cout << "read message is : ";
        write(STDOUT_FILENO, buf, n);
    }
}

int main(int argc, const char *argv[])
{
    int listenFd, connFd, sockFd;
    struct sockaddr_in clientAddr;
    socklen_t clientAddrLen;
    listenFd = socket_bind()
    return 0;
}



