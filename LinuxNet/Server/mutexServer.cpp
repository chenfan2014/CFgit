#include "header.h"
#define CLINET_NUM 2

using namespace std;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
static void *handleRequest(void *arg)
{
    int serverfd = *((int *)arg);
    int clientfd;
    struct sockaddr_in clientAddr;
    socklen_t clientAddrLen = sizeof(clientAddr);
    
    for(;;)
    {
        time_t now;
        char buffer[MAXSIZES];
        memset(buffer, 0, MAXSIZES);

        pthread_mutex_lock(&mutex);
        clientfd = accept(serverfd, (struct sockaddr *)&clientAddr, &clientAddrLen);
        if(clientfd == -1){
            ERR_EXIT("accept error");
        }

        pthread_mutex_unlock(&mutex);

        int n = recv(clientfd, buffer, MAXSIZES, 0);
        if(n == -1){
            ERR_EXIT("recv error");
        }

        cout << "Recv : " << buffer << endl;
        memset(buffer, 0, MAXSIZES);
        now = time(NULL);
        sprintf(buffer, "%24s\r\n", ctime(&now));
        send(clientfd, buffer, strlen(buffer), 0);
    }
    close(clientfd);

}

static void handleConnection(int serverfd)
{
    pthread_t thread[CLINET_NUM];
    
    int i = 0;
    for(i = 0; i != CLINET_NUM; i ++){
        pthread_create(&thread[i], NULL, handleRequest, (void *)&serverfd);
    }

    for(i = 0; i != CLINET_NUM; i ++){
        pthread_join(thread[i], NULL);      //等待线程解数
    }
}

int main(int argc, const char *argv[])
{
    int serverfd;
    struct sockaddr_in serverAddr;

    if((serverfd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        ERR_EXIT("error socket");
    }

    bzero(&serverAddr, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    inet_pton(AF_INET, IPADDRESS, &serverAddr.sin_addr);

    if(bind(serverfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1){
        ERR_EXIT("bind error");
    }

    if(listen(serverfd, LISTENSIZE) == -1){
        ERR_EXIT("error listen");
    }

    close(serverfd);
    return 0;
}
