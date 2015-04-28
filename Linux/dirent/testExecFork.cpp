#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)
int main(int argc, const char *argv[])
{
    const int MAXLINE = 1024;
    char buf[MAXLINE];
    pid_t pid;
    int status;
    printf("%%");
    while(fgets(buf, MAXLINE, stdin) != NULL){
        if(buf[strlen(buf) - 1] == '\n'){
            buf[strlen(buf) - 1] = '\0';
        }
    }

    if((pid = fork()) == 0){
        execlp(buf, buf, (char *)0);
            ERR_EXIT("error exec");
            exit(1);
    }else if(pid < 0){
        ERR_EXIT("fork error");
    }

    if((pid = waitpid(pid, &status, 0)) < 0){
        ERR_EXIT("waitpid error");
    }
    return 0;
}

