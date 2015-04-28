#include <iostream>
#include <string>
#include <vector>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <time.h>
#include <errno.h>

#define MAXSIZE 1024
#define IPADDRESS "127.0.0.1"
#define PORT 9898
#define FDSIZE 1024
#define EPOLLEVENTS 20

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

static void handle_connection(int );

static void handle_events(int epollfd, struct epoll_event *events, int num, int sockfd, char *buf);

static void do_read(int epollfd, int fd, int sockfd, char *buf);
static void do_write(int epollfd, int fd, int sockfd, char *buf);

static void add_event(int epollfd, int fd, int state);
static void delete_event(int epollfd, int fd, int state);
static void modify_event(int epollfd, int fd, int state);

int main(int argc, const char *argv[])
{
    int sockfd;
    struct sockaddr_in serverAddr;
    
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        ERR_EXIT("socket error");
    }

    bzero(&serverAddr, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    inet_pton(AF_INET, IPADDRESS, &serverAddr.sin_addr); 
    //字符串转变成二进制
    
    if(connect(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1){
        ERR_EXIT("connect error");
    }

    handle_connection(sockfd);

    close(sockfd);

    return 0;
}

static void handle_connection(int sockfd)
{
    int epollfd;
    struct epoll_event events[EPOLLEVENTS];
    char buf[MAXSIZE];
    int ret;

    epollfd = epoll_create(FDSIZE); 
    /*
     * 上面int epoll_create(int size);这个函数是创建一个epoll句柄
     * 的函数，size用来告诉内核这个监听的数目一共有多大
     * 这个参数不同于select的第一个参数
     * 需要注意的是，当我们创建好epoll句柄的时候，它就是会占用
     * 一个fd值，也就是占用一个文件描述符，所以在我们使用完了
     * epoll之后，我们需要进行关闭close()。否则可能导致fd被耗尽
     */
    
    add_event(epollfd, STDIN_FILENO, EPOLLIN);

    while(1)
    {
       ret = epoll_wait(epollfd, events, EPOLLEVENTS, -1);
       /*
        * 上面这个是等待事件的产生，类似于select调用，
        * int epoll_wait(int epfd, struct epoll_event *events, int maxevents, int timeout);
        * 参数events用来从内核得到事件的集合，maxevents告之内核
        * 这个events有多大，这个maxevents的值不能大于创建
        * epoll_create的时候的size的值，参数timeout是超时时间
        * 单位为毫秒，0立即返回，-1将不确定
        */

       handle_events(epollfd, events, ret, sockfd, buf);
    }
    close(epollfd);

}

static void handle_events(int epollfd, struct epoll_event *events, int num, int sockfd, char *buf)
{
    int fd;
    int i;
    for(i = 0; i != num; i ++){
        fd = events[i].data.fd;
        if(events[i].events & EPOLLIN){
            do_read(epollfd, fd, sockfd,  buf);
        }else if(events[i].events & EPOLLOUT){
            do_write(epollfd, fd, sockfd, buf);
        }
    }
}

static void do_read(int epollfd, int fd, int sockfd, char *buf)
{
    int nread;
    nread = read(fd, buf, MAXSIZE);
    if(nread == -1){
        ERR_EXIT("read error");
    }else if(nread == 0){
        cerr << "Server close" << endl;
        close(fd);
    }else{
        if(fd == STDIN_FILENO){
            add_event(epollfd, sockfd, EPOLLOUT);
        }else{
            delete_event(epollfd, sockfd, EPOLLIN);
            add_event(epollfd, sockfd, EPOLLOUT);
        }
    }
}

static void do_write(int epollfd, int fd, int sockfd, char *buf)
{
    int nwrite;
    nwrite = write(fd, buf, strlen(buf));
    if(nwrite == -1){
        ERR_EXIT("write error");
    }else{
        if(fd == STDIN_FILENO){
            delete_event(epollfd, sockfd, EPOLLOUT);
        }else{
            modify_event(epollfd, fd, EPOLLIN);
        }
    }
}

static void add_event(int epollfd, int fd, int state)
{
    struct epoll_event ev;
    ev.events = state;
    ev.data.fd = fd;
    epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &ev); 
    /*
     * 上面这个函数是事件注册函数
     * int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event);
     * EPOLL_CTL_ADD注册新的fd到efpd当中
     * EPOLL_CTL_MOD修改已经注册的fd监听事件
     * EPOLL_CTL_DEL是从epfd中删除一个fd
     */

}

static void modify_event(int epollfd, int fd, int state)
{
    struct epoll_event ev;
    ev.events = state;
    ev.data.fd = fd;
    epoll_ctl(epollfd, EPOLL_CTL_MOD, fd, &ev);
}

static void delete_event(int epollfd, int fd, int state)
{
    struct epoll_event ev;
    ev.events = state;
    ev.data.fd = fd;
    epoll_ctl(epollfd, EPOLL_CTL_DEL, fd， &ev);
}
