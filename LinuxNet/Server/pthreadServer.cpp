#include "header.h"

using namespace std;
static void *handleRequest(void *argv)
{
    int clientfd = *((int *)argv);
    time_t now;
    char buffer[MAXSIZES];
    int n = 0;
    memset(buffer, 0, MAXSIZES);
    
    n = recv(clientfd, buffer, MAXSIZES, 0);
    if(n == -1){
        ERR_EXIT("error recv");
    }
    
    cout << "Recv : " << buffer << endl;

    memset(buffer, 0, MAXSIZES);
    now = time(NULL);
    sprintf(buffer, "%24s\r\n", ctime(&now));
    send(clientfd, buffer, strlen(buffer), 0);

    close(clientfd);
}

static void handleConnection(int serverfd)
{
    struct sockaddr_in clientAddr;
    int clientfd;
    pthread_t threadDo;
    socklen_t clientAddrLen = sizeof(clientAddr);

    while(1)
    {

        if((clientfd = accept(serverfd, (struct sockaddr *)&clientAddr, &clientAddrLen)) == -1){
            ERR_EXIT("error accept");
        }
        //static void *func(void *argc);
        //pthread_create(thread, NULL, func, &cleintfd); 
        pthread_create(&threadDo, NULL, handleRequest, &clientfd);
    }
}

int main(int argc, const char *argv[])
{
    int serverfd;
    struct sockaddr_in serverAddr; 

    if((serverfd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        ERR_EXIT("socket error");
    }

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    inet_pton(AF_INET, IPADDRESS, &serverAddr.sin_addr);

    if(bind(serverfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1){
        ERR_EXIT("bind error");
    }

    if(listen(serverfd, LISTENSIZE) == -1){
        ERR_EXIT("listen error");
    }

    handleConnection(serverfd);
    return 0;
}
