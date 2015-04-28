#include <iostream>
#include <string>
#include <vector>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
using namespace std;

int system(const char *cmdstring){
    pid_t pid;
    int status;

    if(cmdstring == NULL){
        return 1;
    }

    if((pid = fork()) < 0){
        status = -1;
    }else if(pid == 0){ //子进程
        execl("/bin/sh", "sh", "-c", cmdstring, (char *)0);
        _exit(127);         //excel错误
    }else{      //父进程
        while(waitpid(pid, &status, 0) < 0){
            if(errno != EINTR){
                status = -1;
                break;
            }
        }
    }

}

void pr_exit(int status){
    if(WIFEXITED(status)){
        cout << "normal termination, exit status : " << WIFEXITED(status) << endl;
    }else if(WIFSIGNALED(status)){
        cout << "abnormal termination, exit status : " << WTERMSIG(status) << endl;
    }
}

int main(int argc, const char *argv[])
{
    int status = 0;
    if((status = system("date")) < 0){
        cout << "err system() " << endl;
    }
    pr_exit(status);
    return 0;
}
