#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <pthread.h>
#include "apue.h"
using namespace std;

#define MAXSIZE 1024
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

int main(int argc, const char *argv[])
{
    int n;
    int fd[2];
    pid_t pid;
    char line[MAXSIZE];

    if(pipe(fd) < 0){
        ERR_EXIT("error pipe");
    }

    if((pid = fork()) < 0){
        ERR_EXIT("fork error");
    }else if(pid == 0){
        close(fd[1]);
        n = read(fd[0], line, MAXSIZE);
        write(STDOUT_FILENO, line, n);
    }else{
        close(fd[0]);
        string str;
        int size;
        cin >> str;
        size = str.size();
        write(fd[1], str.c_str(), str.size());
    }
    return 0;
}
