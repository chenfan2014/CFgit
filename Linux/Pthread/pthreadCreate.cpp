#include <iostream>
#include <string>
#include <vector>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
using namespace std;

pthread_t ntid;

void printTids(const char *s){
    pid_t pid;
    pthread_t tid;

    pid = getpid();
    tid = pthread_self();
    cout << s << "   Pid : " << pid << " pThread : " << tid << endl;
}

void *thrFn(void *arg){
    printTids("New thread : ");
    return ((void *)0);
}

int main(int argc, const char *argv[])
{
    int err;

    err = pthread_create(&ntid, NULL, thrFn, NULL);
    if(err != 0){
        cout << "can not create pthread" << endl;
        exit(0);
    }
    
    int ret;
    if((ret= pthread_join(ntid, NULL)) != 0){
        cout << "wrong join" << endl;
        exit(0);
    }else{
        cout << "Join success" << endl;
    }

    printTids("Main pthread: ");
    //sleep(1);
    return 0;
}
