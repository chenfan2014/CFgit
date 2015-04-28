#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
using namespace std;
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)
int main(int argc, const char *argv[])
{
    int status;
    if((status = system("date")) < 0){
        ERR_EXIT("system() error");
    }
    cout << endl;
    //exit(status);

    if((status = system("noSuchCommand")) < 0){
        ERR_EXIT("system error");
    }
    cout << endl;
    //exit(status);

    if((status = system("who; exit 44")) < 0){
        ERR_EXIT("system error 1");
    }
    cout << endl;

    if((status = system("ls -l")) < 0){
        ERR_EXIT("system ls error");
    }
    return 0;
}

int system(const char *cmdstring){
    pid_t pid;
    int status;

    if(cmdstring == NULL){
        return 1;
    }

    if((pid = fork()) < 0){
        ERR_EXIT("fork error");
    }else if(pid == 0){
        execl("/bin/sh", "sh", "-c", cmdstring, (char *)0);
        _exit(127); //这个是unistd.h的退出函数，直接退出不清理
    }else{
        while(waitpid(pid, &status, 0) < 0){
            if(errno != EINTR){
                status = -1;
                break;
            }
        }
    }
} 
