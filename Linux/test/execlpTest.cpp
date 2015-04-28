#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

#define ERR_EXIT(m) \
    do{ \
        perror(m);  \
        exit(EXIT_FAILURE);   \
    }while(0)
int main(int argc, const char *argv[])
{
    pid_t pid;
    int status;

    if((pid = fork()) < 0){
        ERR_EXIT("fork() error");
    }else if(pid == 0){
        if(execle("/home/sar/bin/echoall", "echoall", "myarg1", "MYARG2", (char *)10, env_init) < 0){
            ERR_EXIT("execle error");
        }else{
            if(waitpid(pid, NULL, 0) < 0){
                ERR_EXIT("waitpid error");
            }
        }
    }
    return 0;
}
