#include <iostream>
#include <string>
#include <vector>
#include "apue.h"
#include <pthread.h>
using namespace std;

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

struct Foo{
        int a, b, c, d, e;
};
void print(const char *s, const struct Foo *foo){
    cout << *s << endl;
    cout << foo -> a << endl << foo -> b << endl << foo -> c << endl << foo -> d << endl << foo -> e << endl;
}

void *thrFunc1(void *arg){
    struct Foo foo = {1, 2, 3, 4, 5};
    print("thread 1 : ", &foo);
    pthread_exit((void *)&foo);
}

void *thrFunc2(void *arg){
    cout << pthread_self() << endl;
    pthread_exit((void *)0);
}

int main(int argc, const char *argv[])
{
    int err;
    pthread_t tid1, tid2;
    struct Foo *fp;

    if((err = pthread_create(&tid1, NULL, thrFunc1, NULL)) != 0){
        ERR_EXIT("pthread_create 1");
    }
    /*err = pthread_join(tid1, (void *) &fp);
    if(err != 0)
    {
        ERR_EXIT("pthread_join 1");
    }*/

    sleep(1);

    cout << "parent starting second thread" << endl;


    if((err = pthread_create(&tid2, NULL, thrFunc2, NULL)) != 0){
        ERR_EXIT("pthread_create 2");
    }
    sleep(1);
    print("parent : ", fp);


    return 0;
}
