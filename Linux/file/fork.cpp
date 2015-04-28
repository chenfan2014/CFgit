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
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#define BUFFERSIZE 1024
using namespace std;
int main(int argc, const char *argv[])
{
    char buf[BUFFERSIZE] = "";
    pid_t pid;
    int status;

    while(fgets(buf, BUFFERSIZE, stdin) != NULL){
        if(buf[strlen(buf) - 1] == '\n'){
            buf[strlen(buf) - 1] = '\0';   //把\n换成\0
        }
        if((pid = fork()) < 0){
            cout << "father pthread" << endl;
        }else if(pid == 0){
            cout << "son pthread" << endl;
        }
    }

    if( (pid = waitpid(pid, &status, 0)) < 0){
        cout << "waitpid error" << endl;
    }
    return 0;
}
