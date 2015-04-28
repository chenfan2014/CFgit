#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
using namespace std;

#define ERR_EXIT(m) \
    do{     \
        perror(m);  \
        exit(EXIT_FAILURE); \
    }while(0)

static void sigUsr(int signo){
    if(signo == SIGUSR1){
        cout << "received SIGUSR1" << endl;
    }else if(signo == SIGUSR2){
        cout << "receive SIGUSR2" << endl;
    }else{
        cout << "receive signal : " << signo << endl;
    }
}

int main(int argc, const char *argv[])
{
    if(signal(SIGUSR1, sigUsr) == SIG_ERR){
        ERR_EXIT("error signal");
    }
    if(signal(SIGUSR2, sigUsr) == SIG_ERR){
        ERR_EXIT("error signal 2");
    }
    for(; ;){
        pause();
    }
    return 0;
}
