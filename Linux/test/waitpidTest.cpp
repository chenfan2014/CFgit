#include "apue.h"
#include <sys/wait.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)
int main(int argc, const char *argv[])
{
    pid_t pid;
    if((pid = fork()) < 0){
        cout << getppid() << endl;
        ERR_EXIT("fork error");
    }else if(pid == 0){
        if((pid = fork()) < 0){
            ERR_EXIT("fork error");
        }else if(pid > 0){
            cout << "exit success" << endl;
            exit(0);        //第二个子进程的父进程，也就是第一个子进程退出
        }
        sleep(2);
        cout << "second child, parent pid = " << getppid() << endl;
        exit(0);
    }

    if(waitpid(pid, NULL, 0) != pid){
        ERR_EXIT("waitpid error");
    }
    return 0;
}
