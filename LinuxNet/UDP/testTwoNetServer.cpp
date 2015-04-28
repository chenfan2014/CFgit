#include <iostream>
#include <string>
#include <vector>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>         //socket(), bind()
#include <arpa/inet.h>
#include <netinet/in.h>

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
    int serverfd;

    struct sockaddr_in serverAddr;
    struct sockaddr_in localAddr;

    socklen_t localAddrLen = sizeof(localAddr);

    if((serverfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1){
        ERR_EXIT("error socket");
    }

    bzero(&serverAddr, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr(IPADDRESS);

    if(connect(serverfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1){
        ERR_EXIT("error connect");
    }

    getsockname(serverfd, (struct sockaddr *)&localAddr, &localAddrLen);

    cout << "UDP LOCAL addr : " << inet_ntoa(localAddr.sin_addr) << endl;
    return 0;
}
