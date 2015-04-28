#include "socketHead.h"
using namespace std;
int main(int argc, const char *argv[])
{
    int port = 8080;
    const char *ip = "127.0.0.1";
    int sockfd = socketInit(port, ip);
    int clientfd = serverListenAccept(sockfd);
    serverMessage(sockfd, clientfd);
    close(sockfd);
    return 0;
}
