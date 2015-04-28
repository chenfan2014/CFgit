#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

using namespace std;

#define ERR_EXIT(m) \
    do{ \
        perror(m);  \
        exit(0);    \
    }while(1) 

const int port = 8080;

const char ip[] = "127.0.0.1";

int main(int argc, const char *argv[])
{
    int clientfd = socket(AF_INET, SOCK_STREAM, 0);
    if(clientfd == -1){
        ERR_EXIT("socker error");
    }

    struct sockaddr_in clientAddr;
    memset(&clientAddr, 0, sizeof(struct sockaddr));
    clientAddr.sin_family = AF_INET;
    clientAddr.sin_port = htons(port);
    clientAddr.sin_addr.s_addr = inet_addr(ip);
    
    if(connect(clientfd, (struct sockaddr*)&clientAddr, sizeof(struct sockaddr)) == -1){
        close(clientfd);
        ERR_EXIT("error bind");
    }
    cout << "Connect " << ip << " success !" << endl;
    while(1){
        char buf[124] = " ";
        cin >> buf;
        if(send(clientfd, buf, sizeof(buf), 0) == -1){
            close(clientfd);
            ERR_EXIT("send error");
        }
        cout << "Send success : " << buf << endl;
        memset(buf, 0, 124);
        if(recv(clientfd, buf, 124, 0) == -1){
            close(clientfd);
            ERR_EXIT("error recv");
        }
        cout << buf << endl;
    }
    close(clientfd);
    return 0;
}
