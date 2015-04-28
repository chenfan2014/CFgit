#include <iostream>
#include <string>
#include <vector>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
using namespace std;
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

void *threadFuncOne(){
    cout << "Pthread create One" << end;
    return (void *)1;
}

void *threadFuncTwo(){
    cout << "Pthread create two" << endl;
    return (void *)2;
}

int main(int argc, const char *argv[])
{
    pthread_t tidOne, tidTwo;
    int count;
    int ret;

    if((ret = pthread_create(&tidOne, NULL, threadFuncOne, NULL)) != 0){
        ERR_EXIT("error create");
    }
    if((ret = pthread_create(&tidTwo, NULL, threadFuncTwo, NULL)) != 0){
        ERR_EXIT("error create again");
    }


    
    return 0;
}
