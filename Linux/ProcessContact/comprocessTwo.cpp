#include <iostream>
#include <string>
#include <vector>
#include "apue.h"
using namespace std;

static void sigPipe(int signo)
{
    cout << "SIGPIPE caught" << endl;
    exit(1);
}

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

int main(int argc, const char *argv[])
{
    int n, fd1[2], fd2[2];
    pid_t pid;
    char line[1024] = "";

    if(signal(SIGPIPE, sigPipe) == SIG_ERR){
        ERR_EXIT("signal error");
    }

    if(pipe(fd1) < 0 || pipe(fd2) < 0){
        ERR_EXIT("pipe error");
    }

    if((pid = fork()) < 0){
        ERR_EXIT("fork error");
    }else if(pid > 0){                              //父进程
        close(fd1[0]);      //关闭fd1读端
        close(fd2[1]);      //关闭fd2写端

        while(fgets(line, 1024, stdin) != NULL){    //标准输入输入数据到line中
            n = strlen(line);
            if(write(fd1[1], line, n) != n){        //把line中的数据写到fd1[1]当中去，子进程可以通过fd1读端进行读出
                ERR_EXIT("write fd1 error");       
            }

            if((n = read(fd2[0], line, 1024)) < 0){ //这里可以读取出内容
                ERR_EXIT("read error");
            }

            if(n == 0){     //没有数据
                ERR_EXIT("child closed pipe");
            }

            line[n] = 0;    //n != 0;
            if(fputs(line, stdout) == EOF){         //打印的是子进程的写入的内容
                ERR_EXIT("fputs error");
            }
        }

        if(ferror(stdin)){
            ERR_EXIT("stdin");
        }
        exit(0);
    }else{
        close(fd1[1]);
        close(fd2[0]);

        if(fd1[0] != STDIN_FILENO){                 //把fd1的读端设置为标准输入，也就是标准输入作为读端
            if(dup2(fd1[0], STDIN_FILENO) != STDIN_FILENO){
                ERR_EXIT("dup2 error stdin");
            }
            close(fd1[0]);
        }

        if(fd2[1] != STDOUT_FILENO){                //把fd2的写端设置为标准输出，也就是标准输出作为写端
            if(dup2(fd2[1], STDOUT_FILENO) != STDOUT_FILENO){
                ERR_EXIT("dup2 error stdout");
            }
            close(fd2[1]);
        }

        if(execl("./add2", "add2", (char *)0) < 0){
            ERR_EXIT("excel error");
        }
        exit(0);
    }
    return 0;
}
