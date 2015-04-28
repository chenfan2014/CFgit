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

struct foo{
    int a, b, c, d;
};

void printFoo(const char *s, const struct foo *fp){
    cout << s << endl << fp -> a  << endl << fp -> b << endl << fp -> c << endl << fp -> d << endl;
}

void *threadFuncOne(void *arg){
    struct foo f = {1, 2, 3, 4};
    printFoo("Thread one ", &f);
    pthread_exit((void *)&f);
}

void *threadFuncTwo(void *arg){
    cout << endl << "Pthread two ID is  " << pthread_self() << endl;
    pthread_exit((void *)0);
}

int main(int argc, const char *argv[])
{
    int err;
    pthread_t tidOne, tidTwo;
    struct foo *fp;

    if((err = pthread_create(&tidOne, NULL, threadFuncOne, NULL)) != 0){
        ERR_EXIT("pthread create tidOne error");
    }
    if((err = pthread_join(tidOne, NULL)) != 0){
        ERR_EXIT("pthread_join tidone error");
    }
    sleep(1);
    cout << endl << "The second pthread begin" << endl;

    if((err = pthread_create(&tidTwo, NULL, threadFuncTwo, NULL)) != 0){
        ERR_EXIT("error pthread create two");
    }
    sleep(1);
    printFoo("Parent : \n", fp);




    return 0;
}
