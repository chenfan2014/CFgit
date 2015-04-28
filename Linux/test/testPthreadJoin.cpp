#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)


void *funOne(void *arg){
    cout << "Thread One returning" << endl;
    return (void *)1;
}

void *funTwo(void *arg){
    cout << "Thread Two returning " << endl;
    return (void *)1;
}

int main(int argc, const char *argv[])
{
    pthread_t tidOne, tidTwo;
    int err;
    void *tret;

    err = pthread_create(&tidOne, NULL, funOne, NULL);
    if(err != 0){
        ERR_EXIT("pthread create error");
    }

    err = pthread_create(&tidTwo, NULL, funTwo, NULL);
    if(err != 0){
        ERR_EXIT("pthread create error second");
    }

    err = pthread_join(tidOne, &tret);
    if(err != 0){
        ERR_EXIT("pthread join pidOne error");
    }
    cout << "pidOne exit code : "  << tret << endl;

    err = pthread_join(tidTwo, &tret);
    if(err != 0){
        ERR_EXIT("pthread join pidTwo error");
    }
    cout << "pidTwo exit code : " << tret << endl;
    return 0;
}
