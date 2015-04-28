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
#include <netinet/in.h>
#include <arpa/inet.h>

using namespace std;

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

#define IPADDRESS "127.0.0.1"
#define PORT 8989
#define MAXLISTEN 5
#define MAXLINE 1024

int main(int argc, const char *argv[])
{
    struct sockaddr_in serverAddr;
    int serverfd, clientfd;
    socklen_t serverAddrLen;
    int ret;
    char buf[MAXLINE] = "";

    serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if(serverfd == -1){
        ERR_EXIT("error serverfd");
    }
    
    bzero(&serverAddr, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr(IPADDRESS);
    //inet_pton(AF_INET, IPADDRESS, &serverAddr.sin_addr);
    
    if((ret == bind(serverfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr))) == -1){
        ERR_EXIT("bind error");
    }
    
    if((ret = listen(serverfd, MAXLISTEN)) == -1){
        ERR_EXIT("listen error");
    }

    while(1){
        int err;
        int recvNum;
        serverAddrLen = sizeof(serverAddr);
        
        if((clientfd = accept(serverfd, (struct sockaddr *)&serverAddr, &serverAddrLen)) == -1){
            if(errno == EINTR){
                continue;
            }else{
                ERR_EXIT("error accpept");
            }
        }
        
        fprintf(stdout, "Accept a new Clinet : %s : %d\n", inet_ntoa(serverAddr.sin_addr), serverAddr.sin_port);
        while(1){

            int n;
            if((n = recv(clientfd, buf, MAXLINE, 0)) < 0){
                ERR_EXIT("error recv");
            }
            
            cout << "Recv : " << buf << endl;

            char str[] = "Get it";
            if((send(clientfd, str, strlen(str), 0)) < 0){
                ERR_EXIT("send error");
            }
            close(clientfd);
        }
    }

    
    close(serverfd);
    return 0;
}
