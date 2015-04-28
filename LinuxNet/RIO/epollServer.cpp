#include <iostream>
#include <string>
#include <vector>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <sys/types.h>

#define IPADDRESS "127.0.0.1"
#define PORT 9898
#define MAXSIZE 1024
#define LISTENSIZE 5
#define FDSIZE 1000
#define EPOLLEVENTS 100

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

static int socket_bind(const char *ip. int port);   //创建套接字并且进行绑定

static void do_epoll(int listenfd);     //IO多路复用epoll

static void handle_events(int epollfd, struct epoll_event *events, int num, int listenfd, char *buf);   //事件处理函数

static void handle_accept(int epollfd, int listenfd);   //c处理接收到的链接

static void do_read(int epollfd, int fd, char *buf);    //读处理

static void do_write(int epollfd, int fd, char *buf);   //写处理

static void add_event(int epollfd, int fd, int state);  //添加事件

static void modify_event(int epollfd, int fd, int state);   //修改时间

static void delete_event(int epollfd, int fd, int state);   //删除事件

int main(int argc, const char *argv[])
{
    int listenfd;

    listenfd = socket_bind(IPADDRESS, PORT);
    do_epoll(listenfd);
    
    return 0;
}

static int socket_bind(const char *ip, int port)
{
    struct sockaddr_in serverAddr;
    int listenfd;
    
    if((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        ERR_EXIT("socket error");
    }

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &serverAddr.sin_addr);
    //serverAddr.sin_addr.s_addr = inet_addr(ip);
    
    if(listen(listenfd, LISTENSIZE) == -1){
        ERR_EXIT("listen error");
    }

    return listenfd;

}

static void do_epoll(int listenfd)
{
    int epollfd;
    struct epoll_event events[EPOLLEVENTS];
    int ret;
    char buf[MAXSIZE] = ""; 

    epollfd = epoll_create(FDSIZE);     //创建一个epoll描述符

    add_event(epollfd, listenfd, EPOLLIN);

    while(1)
    {
        //下面是获取已经准备好的描述符事件
        ret = epoll_wait(epollfd, events, EPOLLEVENTS, -1); 
        handle_events(epollfd, events, ret, listenfd, buf);
    }
    
    close(epollfd);
}

static void handle_events(int epollfd, struct epoll_event *events, int num, int listenfd, char *buf)
{
    int i;
    int fd;
    
    //进行选好遍历
    for(i = 0; i != num; i ++){
        fd = events[i].data.fd[i];  

        //下面是根据描述符类型和事件类型进行处理
        //
        if((fd == listenfd) && event[i].events & EPOLLIN){
            //这个处理的是socket描述符
            handle_accept(epollfd, listenfd);
        }else if(event[i].events & EPOLLIN){
            //这个处理的是我们的STDIN_FILENO
            do_read(epollfd, fd, buf);
        }else if(event[i].events & EPOLLOUT){
            //这个处理的是我们的STDOUT_FILENO
            do_write(epollfd, fd, buf);
        }
    }
}

//这个是当我们描述符为socket的时候事件处理程序
static void handle_accept(int epollfd, int listenfd)
{
    int clientfd;   
    struct sockaddr_in clientAddr;
    socklen_t clientAddrLen = sizeof(clientAddr);

    clientfd = accept(listenfd, (struct sockadd *)&clientAddr; &clientAddrLen);

    if(clientfd == -1){
        if(errno == EINTR){
            continue;
        }else{
            ERR_EXIT("accept error");
        }
    }

    cout << "Accept a new Clinet : " << inet_ntoa(clientAddr.sin_addr) << " : " << clientAddr.sin_port << endl;

    add_event(epollfd, clientfd, EPOLLIN);
}

//这个是当我们处理STDIN_FILENO描述符的时候执行的程序
static void do_read(int epollfd, int fd, char *buf)
{
    int nread;
    nread = read(fd, buf, MAXSIZE);
    if(nread == -1){
        cerr << "Read error" << endl;
        close(fd);
        delete_event(epollfd, fd, EPOLLIN);
    }else if(nread == 0){
        cerr << "Client close" << endl;
        close(fd);
        delete_event(epollfd, fd, EPOLLIN);
    }else{
        cout << "Message : " << buf << endl;
        modify_event(epollfd, fd, EPOLLOUT);
    }
}

//这个是当我们处理STDOUT_FILENO描述符的时候执行的程序
static void do_write(int epollfd, int fd, char *buf)
{
    int nwrite;
    nwrite = write(fd, buf, strlen(buf));
    if(nwrite == -1){
        close(fd);
        ERR_EXIT("write error");
        delete_event(epollfd, fd, EPOLLOUT)
    }else{
        modify_event(epollfd, fd, EPOLLIN);
        memset(buf, 0, MAXSIZE);
    }
}

//添加一个客户描述符事件
static void add_event(int epollfd, int fd, int state)
{
    struct epoll_event ev;
    ev.events = state;
    ev.data.fd = fd;
    epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &ev)
}


//删除一个客户描述符时间
static void delete_event(int epollfd, int fd, int state)
{
    struct epoll_event ev;
    ev.events = state;
    ev.data.fd = fd;
    epoll_ctl(epollfd, EPOLL_CTL_DEL, fd, &ev);
}

//修改一个客户描述符的事件
static void modify_event(int epollfd, int fd, int state)
{
    struct epoll_event ev;
    ev.events = state;
    ev.data.fd = fd;
    epoll_ctl(epollfd, EPOLL_CTL_MOD, fd, &ev);
}
