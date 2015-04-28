#include <iostream>
#include <string>
#include <vector>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>

using namespace std;

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

#define PORT 8989
#define IPADDRESS "127.0.0.1"
#define MAXSIZE 1024

int main(int argc, const char *argv[])
{
    int clientfd;
    struct sockaddr_in clientAddr;
    char recvStr[MAXSIZE];
    char sendStr[MAXSIZE];

    if((clientfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1){
        ERR_EXIT("socket  error");
    }

    memset(&clientAddr, 0, sizeof(clientAddr));
    clientAddr.sin_family = AF_INET;
    clientAddr.sin_port = htons(PORT);
    clientAddr.sin_addr.s_addr = inet_addr(IPADDRESS);

    while(1)
    {
        memset(recvStr, 0, MAXSIZE);
        memset(sendStr, 0, MAXSIZE);

        int n = read(STDIN_FILENO, sendStr, MAXSIZE);
        socklen_t clientAddrLen = sizeof(clientAddr);

        sendto(clientfd, sendStr, n, 0, (struct sockaddr *)&clientAddr, sizeof(clientAddr));
        recvfrom(clientfd, recvStr, n, 0, (struct sockaddr *)&clientAddr, &clientAddrLen);
        cout << "Recv from : " << recvStr << endl;
    }

    return 0;
}

