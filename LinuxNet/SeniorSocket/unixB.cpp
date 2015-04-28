#include <iostream>
#include <string>
#include <vector>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/wait.h>
#include <error.h>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

#define BUFFERSIZE 1024

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)


ssize_t recv_fd(int fd, void *data, size_t bytes, int *recvfd)
{
    struct msghdr msghdrRecv;
    struct iovec iov[1];
    size_t n;

    union{
        struct cmsghdr cm;
        char control[CMSG_SPACE(sizeof(int))];
    }control_un;

    struct cmsghdr *pcmsghdr;
    msghdr_recv.msg_control = control_un.control;
    msghdr_recv.msg_controllen = sizeof(control_un.control);

    msghdrRecv.msg_name = NULL;
    msghdrRecv.msg_namelen = 0;

    iov[0].iov_base = data;
    iov[0].iov_len = bytes;
    msghdrRecv.msg_iov = iov;
    msghdrRecv.msg_iovlen = 1;

    if((n = recvmsg(fd, &msghdrRecv, 0)) < 0){
        return n;
    }

    if((pcmsghdr = CMSG_FIRSTHDR(&msghdrRecv)) != NULL && pcmsghdr -> cmsg_len == CMSG_LEN(sizeof(int))){
        if(pcmsghdr -> cmsg_level != SOL_SOCKET){
            cout << "control level != SOL_SOCKET" << endl;
        }
        if(pcmsghdr -> cmsg_type != SCM_RIGHTS){
            cout << "control types != SCM_RIGHTS" << endl;
        }

        *recvfd = *((int *)CMSG_DATA(pcmsghdr));
    }else{
        *recvfd = -1;
    }
    return n;
}

int my_open(const char *pathname, int mode)
{
    int fd, sockfd[2], status;
    pid_t childpid;
    char c, argsockfd[10], argmode[10];

    //建立一对匿名的已经链接的套接字，两个套接字描述符放在sockfd[0]和sockfd[1]当中
    socketpair(AF_LOCAL, 0, SOCK_STREAM, sockfd);       //协议族，类型，协议，套接字组
    if((childpid = fork()) == 0){       //子进程
        close(sockfd[0]);
        snprintf(argsockfd, sizeof(argsockfd), "%d", sockfd[1]);

        snprintf(argmode, sizeof(argmode), "%d", mode);

        excel("./openfile", "openfile", argsockfd, pathname, argmode, (char *)NULL);

        cout << "excel error" << endl;
    }

    //父进程
    close(sockfd[1]);
    waitpid(childpid, &status, 0);

    if(WIFEXITED(status) == 0){
        cout << "child did not terminate" << endl;
    }
    if((status = WEXITSTATUS(status)) == 0){
        recv_fd(sockfd[0], &c, 1, &fd);
    }else{
        errno = status;
        fd = -1;
    }
    
    close(sockfd[0]);
    return fd;
}

int main(int argc, const char *argv[])
{
    int fd, n;
    char buffer[BUFFERSIZE];

    if(argc != 2){
        ERR_EXIT("error args");
    }

    if((fd = my_open(argv[1], O_RDONLY)) < 0){
        ERR_EXIT("open error");
    }

    while((n = read(fd, buffer, BUFFERSIZE)) > 0){
        write(STDOUT_FILENO, buffer, n);
    }

    return 0;
}


