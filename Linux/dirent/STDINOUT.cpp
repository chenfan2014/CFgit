#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>     
//STDIN_FILENO, STDOUT_FILENO,这两个函数是POSIX的一部分，unistd中包含了很多的UNIX系统服务函数原型
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)
int main(int argc, const char *argv[])
{
    const int BUFFERSIZE = 1024;
    int n;

    char buf[BUFFERSIZE];

    while((n = read(STDIN_FILENO, buf, BUFFERSIZE)) > 0){
        if(write(STDOUT_FILENO, buf, n) != n){
            ERR_EXIT("Wrong write to stdout");
        }
    }

    if(n < 0){
        ERR_EXIT("read error");
    }
    return 0;
}
