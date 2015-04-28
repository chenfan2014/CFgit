#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

using namespace std;

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

void cleanup(void *arg){
    cout << "CleanUp : " << (char *)arg << endl;
}

void *threadFuncOne(void *arg){
    cout << "Thread One Begin" << endl;
    pthread_cleanup_push(cleanup, "Thread 1 first handler");
    pthread_cleanup_push(cleanup, "Thread 1 second handler");
    cout << "Pthread 1 push complete" << endl;

    if(arg){
        return ((void *)1);
    }

    pthread_cleanu_pop(0);
    pthread_cleanu_pop(0);
    return ((void *)1);
}

void *threadFuncTwo(void *arg){
    cout << "Thread Second begin " << endl;
    pthread_cleanup_push(cleanup, "Thread 2 first handler");
    pthread_cleanup_push(cleanup, "Thread 2 second handler");
    cout << "Pthread 2 push complete" << endl;

    if(arg){
        return ((void *)2);
    }

    pthread_cleanu_pop(0);
    pthread_cleanu_pop(0);
    return ((void *)2);

}


int main(int argc, const char *argv[])
{
    pthread_t tidOne, tidTwo;
    int err;
    void *tret;

    if((err = pthread_create(&tidOne, NULL, threadFuncOne, NULL)) != 0){
        ERR_EXIT("pthread create one error");
    }
    if((err = pthread_create(&tidTwo, NULL, threadFuncTwo, NULL)) != 0){
        ERR_EXIT("pthread create two error");
    }

    if((err = pthread_join(tidOne, &tret)) != 0){
        ERR_EXIT("pthread join one error");
    }
    cout << "Thread One exit code " << tret << endl;

    if((err = pthread_join(tidTwo, &tret) != 0)){
        ERR_EXIT("Thread join error two");
    }
    cout << "Thread Two exit code" << tret << endl;

    return 0;
}
