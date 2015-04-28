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
using namespace std;
int main(int argc, const char *argv[])
{
    pid_t fpid;
    if((fpid = fork()) < 0){
        cout << "Wrong fork" << endl;
    }else if(fpid == 0){
        pid_t pid;
        if((pid = fork()) < 0){
            cout << "Wrong fork 2" << endl;
        }else if(pid == 0){
            cout << " Second PID : " << getpid() << " PPID ： " << getppid() << endl; 
        }else{
            exit(0);   
        }
        cout << " First son PID : " << getpid() << " PPID ： " << getppid() << endl; 
        
    }else{
        exit(0);
    }

return 0;
}
