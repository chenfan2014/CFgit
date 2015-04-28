#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAXSIZE 1024
using namespace std;
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)
int main(int argc, const char *argv[])
{
    char buf[1024] = "";
    pid_t pid;
    int status;
    int sig_int;
    if(signal(SIGINT, sig_int) == SIG_ERR){
        ERR_EXIT("signal");
    }

    while(fgets(buf, MAXSIZE, stdin) != NULL){
        if(buf[strlen(buf) - 1] = '\n'){
            buf[strlen(buf) - 1] = '\0';
        }
        if((pid = fork()) < 0){
            ERR_EXIT("fork error");
        }else if(pid == 0){
            cout << "Son pid yes" << endl;
        }
    }
    return 0;
}
