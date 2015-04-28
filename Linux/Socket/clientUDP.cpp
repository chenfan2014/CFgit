#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;    
int main(int argc, char* argv[])
{
    int sfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sfd == -1)
    {
        perror("socket");
        exit(-1);
    }

    struct sockaddr_in toaddr;
    bzero(&toaddr, sizeof(toaddr));
    toaddr.sin_family = AF_INET;
    toaddr.sin_port = htons(atoi(argv[2])); //此处的端口号要跟服务器一样
    toaddr.sin_addr.s_addr = inet_addr(argv[1]); //此处为服务器的ip
    char sendBuf[1024] = " ";
    while(1){
        cin >> sendBuf;
        sendto(sfd, sendBuf, sizeof(sendBuf), 0, (struct sockaddr*)&toaddr, sizeof(struct sockaddr));

        char buf[512] = {0};
        struct sockaddr_in fromaddr;
        bzero(&fromaddr, sizeof(fromaddr));
        socklen_t fromaddrlen = sizeof(struct sockaddr);
        if(recvfrom(sfd, buf, sizeof(buf), 0, (struct sockaddr*)&fromaddr, &fromaddrlen) == -1)
        {
            perror("recvfrom");
            close(sfd);
            exit(-1);
        }
        cout << "Recvfrom : " << buf << endl;
    }
    close(sfd);
}
