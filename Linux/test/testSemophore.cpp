#include <stdio.h>
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>
using namespace std;
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

sem_t sem;
int running = 1;

void *producerFunc(void *);
void *consumerFunc(void *);

int main(int argc, const char *argv[])
{
    pthread_t consumer;
    pthread_t producer;
    sem_init(&sem, 0, 16);  //第二个参数为0表示线程共享，如果不为0则是线程不共享，16为信号量初始化的时候的值
    
    pthread_create(&producer, NULL, producerFunc, NULL);
    pthread_create(&consumer, NULL, consumerFunc, NULL);

    sleep(1);

    running = 0;
    pthread_join(producer, NULL);
    pthread_join(consumer, NULL);

    sem_destroy(&sem);
    return 0;
}
void *producerFunc(void *arg){
    int semValue = 0;
    while(running){
        usleep(1);
        sem_post(&sem);
        sem_getvalue(&sem, &semValue);
        cout << "Total producer: " << semValue << endl;
    }
}

void *consumerFunc(void *arg){
    int semValue = 0;
    while(running){
        usleep(1);
        sem_wait(&sem);
        sem_getvalue(&sem, &semValue);
        cout << "Total consumer : " << semValue << endl;
    }
}
