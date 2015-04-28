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
#include <sys/un.h>
#include <signal.h>

using namespace std;

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

int main(int argc, const char *argv[])
{
    int err;
    int sock_unix;
    struct sockaddr_un unixAddr;
    int unixLen;
    const char path[] = "/demon/path";

    sock_unix = socket(AF_UNIX, SOCK_STREAM, 0);
    if(sock_unix == 0){
        ERR_EXIT("socket error");
    }

    unlink(path);   //这是以为之前path已经用作其他用户，这样我们将之前的绑定取消

    memset(&unixAddr, sizeof(unixAddr));
    unixAddr.sun_family = AF_LOCAL;
    strcpy(unixAddr.sun_path, path);
    unlxLen = sizeof(struct sockaddr_un);

    //绑定地址到socket sock_unix
    if((err = bind(sock_unix, (struct sockaddr_un *)&unixAddr, sizeof(unixAddr))) == -1){
        ERR_EXIT("bind error");
    }

    close(sock_unix);
    unlink(path);

    return 0;
}
