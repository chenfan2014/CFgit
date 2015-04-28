#include <iostream>
#include <string>
#include <vector>
#include <pthread.h>
#include "apue.h"
using namespace std;

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

void cleanup(void *arg){
    cout << "clean up" << arg << endl;
}

void *thrFuncOne(void *arg){
    cout << "thread function one start" << endl;
    pthread_cleanup_push(cleanup, "thread 1 first handler ");
    pthread_cleanup_push(cleanup, "thread 1 second handler ");
    cout << "pthread 1 push complete" << endl;
    if(arg){
        return ((void*)1);
    }
    pthread_cleanup_pop(0);     //参数为0,清理函数将不被调用
    pthread_cleanup_pop(0);
    pthread_exit((void *)1);
}

void *thrFuncTwo(void *arg){
    cout << "thread function two start" << endl;
    pthread_cleanup_push(cleanup, "thread 2 first handler ");
    pthread_cleanup_push(cleanup, "thread 2 second handler ");
    cout << "pthread 2 push complete" << endl;
    if(arg){
        return ((void*)2);
    }
    pthread_cleanup_pop(0);     //参数为0,清理函数将不被调用
    pthread_cleanup_pop(0);
    pthread_exit((void *)2);
}

int main(int argc, const char *argv[])
{
    int err;
    pthread_t tidOne, tidTwo;
    void *tret;

    if((err = pthread_create(&tidOne, NULL, thrFuncOne, (void *)1)) != 0){
        ERR_EXIT("pthread_create 1 ");
    }
    
    if((err = pthread_create(&tidTwo, NULL, thrFuncTwo, (void *)1)) != 0){
        ERR_EXIT("pthread_create 2 ");
    }

    if((err = pthread_join(tidOne, &tret)) != 0){
        ERR_EXIT("pthread_join 1");
    }
    cout << "Pthread one exit code : " << tret << endl;

    if((err = pthread_join(tidTwo, &tret)) != 0){
        ERR_EXIT("pthread_join 2");
    }
    cout << "Pthread two exit code : " << tret << endl;

    return 0;
}
