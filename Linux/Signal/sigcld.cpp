#include <iostream>
#include <string>
#include <vector>
#include <signal.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
using namespace std;

static void sigcld(int signo){
    pid_t pid;
    int status;

    cout << "sigcld received" << endl;

    if(signal(SIGCLD, sigcld) == SIG_ERR){
        cout << "signal sigcld error " << endl;
    }

    if((pid = wait(&status)) < 0){
        cout << "wait error " << endl;
    }
}

int main(int argc, const char *argv[])
{
    pid_t pid;

    if(signal(SIGCLD, sigcld) == SIG_ERR){
        cout << "sig err " << endl;
    }

    if((pid = fork()) < 0){
        cout << "fork error" << endl;
    }else if(pid == 0){
        sleep(2);
        _exit(0);
    }

    
    return 0;
}
