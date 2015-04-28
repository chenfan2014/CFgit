#include "socketHead.h"
using namespace std;
int main(int argc, const char *argv[])
{
    int port = 8080;
    const char *ip = "127.0.0.1";
    int clientfd = clientConnect(port, ip);
    clientMessage(clientfd);
    close(clientfd);
    return 0;
}
