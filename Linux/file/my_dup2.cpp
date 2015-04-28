#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>
#define MAX 1000
using namespace std;
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

int myDup2(int filedes,int filedes2)
{  
    if(filedes2==filedes){  
        return filedes;  
    }
    close(filedes2); 
    //dup2中判断是否相等，相等则返回，不相等如果打开则关闭，所以我们使用了关闭
    int fd_list[MAX] = {0}; 
    int i, j;

    cout << filedes2 << endl;
    cout << filedes << endl;
    for(i = 0; i <= filedes2; i++)
    {
        if((fd_list[i] = dup(filedes)) < 0){
            ERR_EXIT("fd_list");
        }
        if(fd_list[i] == filedes2){
            cout << "in" << endl;
            break;
        }
    }
    cout << i << endl;
    for(j = 0; j < i; j ++){
        close(fd_list[j]);  
    }
    return fd_list[i];
}  

int main(int argc, const char *argv[])
{
    int oldfd = open("test.txt", O_RDONLY);
    int newfd;
    if(oldfd == -1){
        ERR_EXIT("open");
    }
    int iret;
    if((iret = myDup2(oldfd, newfd)) == -1){
        ERR_EXIT("myDup2");
    }else{
        int nread;
        char buf[1024] = "";
        while((nread = read(newfd, buf, 1024)) > 0){
            write(STDOUT_FILENO, buf, nread);
        }
    }
    close(oldfd);
    close(newfd);
    return 0;
}
