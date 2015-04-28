#include <iostream>
#include <string>
#include <vector>
#include <signal.h>
#include <unistd.h>
using namespace std;

static void sig_usr(int signo){
    if(signo == SIGUSR1){
        cout << "receive SIGUSR1" << endl;
    }else if(signo == SIGUSR2){
        cout << "receive SIGUSR2" << endl; 
    }else{
        cout << "receive other signal " << endl;
    }
}

int main(int argc, const char *argv[])
{
    if(signal(SIGUSR1, sig_usr) == SIG_ERR){
        cout << "can not catch SIGUSR1" << endl;
    }
    if(signal(SIGUSR2, sig_usr) == SIG_ERR){
        cout << "can not catch SIGUSR2" << endl;
    }
    for( ; ; )
        pause();
    return 0;
}
