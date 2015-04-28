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

#define DEFPAGER "/bin/more

int main(int argc, const char *argv[])
{
    int n;
    int fd[2];
    pid_t pid;
    char *pager, *argv0;
    char line[1024];
    FILE *fp;

    if(argc != 2){
        ERR_EXIT("error argc");
    }
    
    if((fp = fopen(argv[1], "r")) == NULL){
        ERR_EXIT("err fopen");
    }
    
    if(pipe(fd) < 0){
        ERR_EXIT("err pipe fd");
    }

    if((pid = fork()) < 0){
        ERR_EXIT("can not fork");
    }else if(pid > 0){
        close(fd[0]);
        while(fgets(line, 1024, fp) != NULL){
            n = strlen(line);
            if(write(fd[1], line, n) != n){
                ERR_EXIT("err write fd[1]");
            }
        }
        close(fd[1]);
        if(waitpid(pid, NULL, 0) < 0){
            ERR_EXIT("waitpid err");
        }
    }else{
        close(fd[1]);
        if(fd[0] != STDIN_FILENO){
            if(dup2(fd[0], STDOIN_FILENO) != STDIN_FILENO){
                ERR_EXIT(dup2 err);
            }
            close(fd[0]);
        }
    }
    return 0;
}
