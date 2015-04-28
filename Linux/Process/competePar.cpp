#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <signal.h>
using namespace std;

static void charataTime(char *str){
    char *ptr;
    int c;

    setbuf(stdout, NULL);
    for(ptr = str; (c = *ptr ++) != 0; ){
        putc(c, stdout);
    }
    cout << endl;
}

void TELL_WAIT(void)
{
        if (signal(SIGUSR1, sig_usr) == SIG_ERR)
                err_sys("signal(SIGUSR1) error");
        if (signal(SIGUSR2, sig_usr) == SIG_ERR)
                err_sys("signal(SIGUSR2) error");
        sigemptyset(&zeromask);
        sigemptyset(&newmask);
        sigaddset(&newmask, SIGUSR1);
        sigaddset(&newmask, SIGUSR2);

        if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
                err_sys("SIG_BLOCK error");
}

int main(int argc, const char *argv[])
{
    pid_t pid;
    
    TELL_WAIT();

    if((pid = fork()) < 0){
        cout << "err fork " << endl;
    }else if(pid == 0){
        WAIT_PARENT();
        charataTime("output from child\n");
    }else{
        charataTime("output from parent\n");
        TELL_CHLD();
    }

    return 0;
}
