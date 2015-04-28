//判断套接字描述符判定函数issockettype()
//首先我们如果要判断文件描述符是否为套接字描述符
//首先我们调用函数fstat()获取文件描述符的模式
//然后我们将模式的S_IFMT与标识符S_IFSOCK进行比较
//如果相等，那么表示这个文件描述符是套接字描述符
//下面是一个测试用例

#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
int issockettype(int fd){
    struct stat st;
    int err = fstat(fd, &st);
    if(err == -1){
        return -1;
    }
    if((st.st_mode & S_IFMT) == S_IFSOCK){
        return 1;
    }else{
        return 0;
    }
}
int main(int argc, const char *argv[])
{
    int first = issockettype(0);
    printf("value of first is : %d\n", first);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    int second = issockettype(sockfd);
    printf("value of second is %d\n" ,  second);
    return 0;
}
