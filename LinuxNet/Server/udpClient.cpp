#include <iostream>
#include <string>
#include <vector>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

using namespace std;

#define PORT 8989
#define IPADDRESS "127.0.0.1"
#define MAXSIZE 1024
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

int main(int argc, const char *argv[])
{
    int clientfd;
    struct sockaddr_in clientAddr;
    char recvStr[MAXSIZE], sendStr[MAXSIZE];
    socklen_t clientAddrLen = sizeof(clientAddr);

    if((clientfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1){
        ERR_EXIT("socket error");
    }

    bzero(&clientAddr, sizeof(clientAddr));
    clientAddr.sin_family = AF_INET;
    clientAddr.sin_port = htons(PORT);
    clientAddr.sin_addr.s_addr = inet_addr(IPADDRESS);

    memset(recvStr, 0, MAXSIZE);
    memset(sendStr, 0, MAXSIZE);

    int n = read(STDIN_FILENO, sendStr, MAXSIZE);
    if(n == -1){
        ERR_EXIT("error read;");
    }
    
    cout << time(NULL) << endl;

    if(sendto(clientfd, sendStr, n, 0, (struct sockaddr *)&clientAddr, clientAddrLen) == -1){
        ERR_EXIT("sendto error");
    }
    cout << "Send Succes" << endl;


    if(recvfrom(clientfd, recvStr, MAXSIZE, 0, (struct sockaddr *)&clientAddr, &clientAddrLen) == -1){
        ERR_EXIT("recv error");
    }
    cout << "Recv from server : " << recvStr << endl;

    return 0;
}
