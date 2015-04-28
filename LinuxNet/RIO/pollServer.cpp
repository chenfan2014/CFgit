#include <iostream>
#include <string>
#include <vector>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <poll.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>


using namespace std;

#define PORT 9999
#define IPADDRESS "127.0.0.1"
#define MAXLINE 1024
#define LISTENMAX 5
#define OPENMAX 1000
#define INFTIM -1

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

static int socket_bind(const char *ip, int port);

static void do_poll(int listenfd);

static void handler_connection(struct pollfd *, int );

int main(int argc, const char *argv[])
{
    int listenfd, connfd, sockfd;
    struct sockaddr_in cliaddr;
    socklen_t cliaddrlen;

    listenfd = socket_bind(IPADDRESS, PORT);
    
    if(listen(listenfd, LISTENMAX) == -1){
        ERR_EXIT("listen error");
    }

    do_poll(listenfd);
    return 0;
}

static int socket_bind(const char *ip, int port)
{
    int listenfd;
    struct sockaddr_in servaddr;

    if((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        ERR_EXIT("socket error");
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &servaddr.sin_addr);
    //inet_pton(AF_INET, ip, &servaddr.sin_addr);

    if(bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1){
        ERR_EXIT("bind error");
    }

    return listenfd;
}


static void do_poll(int listenfd)
{
    int connfd, sockfd;
    struct sockaddr_in clientAddr;
    socklen_t clientAddrLen;
    struct pollfd clientpfds[OPENMAX];
    int maxi;
    int i;
    int nready;

    clientpfds[0].fd = listenfd;
    clientpfds[0].events = POLLIN;

    for(i = 1; i != OPENMAX; i++){
        clientpfds[i].fd = -1;
    }

    maxi = 0;

    while(1)
    {
        nready = poll(clientpfds, maxi + 1, INFTIM);
        if(nready == 0){
            ERR_EXIT("poll error");
        }

        if(clientpfds[0].fd & POLLIN){
            clientAddrLen = sizeof(clientAddr);

            if((connfd = accept(listenfd, (struct sockaddr *)&clientAddr, &clientAddrLen)) == -1){
                if(errno == EINTR){
                    continue;
                }else{
                    ERR_EXIT("error accept");
                }
            }

            cout << "Accept a new clinet : " << inet_ntoa(clientAddr.sin_addr) << " : " << clientAddr.sin_port << endl;

            for(i = 1; i != OPENMAX; i ++){
                if(clientpfds[i].fd == -1){
                    clientpfds[i].fd = connfd;
                    break;
                }
            }

            if(i == OPENMAX){
                cout << "Too much client" << endl;
            }

            clientpfds[i].events = POLLIN;

            maxi = (maxi > i ? maxi : i );
            if(--nready <= 0){
                continue;
            }
        }
        handler_connection(clientpfds, maxi);
    }
}

static void handler_connection(struct pollfd *connfds, int num)
{
    int i, n;
    char buffer[MAXLINE];

    for(i = 1; i != num; i ++){
        if(connfds[i].fd < 0){
            continue;
        }

        if(connfds[i].revents & POLLIN){
            n = recv(connfds[i].fd, buffer, MAXLINE, 0);
            if(n == 0){
                close(connfds[i].fd);
                connfds[i].fd = -1;
                continue;
            }
        }
        cout << "RECV : " << buffer << endl;
        send(connfds[i].fd, buffer, n, 0);
    }

}
