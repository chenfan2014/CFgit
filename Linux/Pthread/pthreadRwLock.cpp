#include <iostream>
#include <string>
#include <vector>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

struct job{
    struct job *jNext;
    struct job *jPre;
    pthread_t jId;
};

struct queue{
    struct job *qHead;
    struct job *qTail;
    pthread_rwlock_t qLock;
};

int queueInit(struct queue *qp){
    int err;

    qp -> qHead = NULL;
    qp -> qTail = NULL;
    if((err = pthread_rwlock_init(&qp -> qLock, NULL)) != 0){
        ERR_EXIT("pthread_rwlock_init");
    }
}

void jobInsert(struct queue *qp, struct job *jp){
    pthread_rwlock_wrlock(&qp -> qLock);
    jp -> jNext = qp -> qHead;
    jp -> jPre = NULL;
    if(qp -> qHead != NULL){
        qp -> qHead -> jPre = jp;
    }else{
        qp -> qTail = jp;
    }
    qp -> qHead = jp;
    pthread_rwlock_unlock(&qp -> qLock);
}

void jobAppend(struct queue *qp, struct job *jp){
    pthread_rwlock_init(&qp -> qLock, NULL);
    jp -> jNext = NULL;
    jp -> jPre = qp -> qTail;
    if(qp -> qTail != NULL){
        qp -> qTail -> jNext = jp;
    }else{
        qp -> qHead = jp;
    }
    qp -> qTail = jp;
    pthread_rwlock_unlock(&qp -> qLock);
}

void jobRemove(struct queue *qp, struct job *jp){
    pthread_rwlock_init(&qp -> qLock, NULL);
    if(jp == qp -> qHead){  
        qp -> qHead = jp -> jNext;
        if(qp -> qTail == jp){
            qp -> qTail = NULL;
        }else{
            jp -> jNext -> jPre = jp -> jPre;
        }
    }else if(jp = qp -> qTail){
        qp -> qTail = jp -> jPre;
        jp -> jPre -> jNext = jp -> jNext;
    }else{
        jp -> jPre -> jNext = jp -> jNext;
        jp -> jNext -> jPre = jp -> jPre;
    }
    pthread_rwlock_unlock(&qp -> qLock);
}

struct job *jobFind(struct queue *qp, pthread_t pid){
    struct job *jp;
    if(pthread_rwlock_rdlock(&qp -> qLock) != 0){
        return NULL;
    }

    for(jp = qp -> qHead; jp != NULL; jp = jp -> jNext){
        if(pthread_equal(jp -> jId, pid)){
            break;
        }
    }
    pthread_rwlock_unlock(&qp -> qLock);
    return (jp);



}

int main(int argc, const char *argv[])
{
    
    return 0;
}
