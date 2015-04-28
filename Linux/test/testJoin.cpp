#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
using namespace std;
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)


void *threadFuncOne(void *arg){
    cout << "Thread one create" << endl;
    return (void *)1;
}

void *threadFuncTwo(void *arg){
    cout << "thread two create " << endl;
    return (void *)2;
}


int main(int argc, const char *argv[])
{
    int err;
    pthread_t tid1, tid2;
    void *tret;

    if((err = pthread_create(&tid1, NULL, threadFuncOne, NULL)) != 0){
        ERR_EXIT("pthread create tid1 err");
    }
    sleep(1);
    if((err = pthread_create(&tid2, NULL, threadFuncTwo, NULL)) != 0){
        ERR_EXIT("pthread create tid2 err");
    }

    if((err = pthread_join(tid1, &tret)) != 0){
        ERR_EXIT("pthread join tid1 err");
    }
    cout << "tid1 exit code : " << tret << endl;

    if((err = pthread_join(tid2, &tret)) != 0){
        ERR_EXIT("pthread code tid2 err ");
    }
    cout << "tid2 exit code " << tret << endl;
    return 0;
}
