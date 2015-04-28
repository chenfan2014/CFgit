#include <iostream>
#include <string>
#include <vector>
#include <pthread.h>
#include <stdlib.h>

#define NHASH 29
#define HASH(id) (((unsigned long)id) %NHASH)

struct Foo *fh[NHASH];

pthread_mutex_t hashLock = PTHREAD_MUTEX_INITIALIZER;
struct Foo{
    int fCount;
    pthread_mutex_t fLock;
    int fId;
    struct Foo *fNext;
};


struct Foo *fooAlloc(int id){
    struct Foo *fp;
    int idx;

    if((fp = (Foo *)malloc(sizeof(struct Foo))) != NULL){
        fp -> fCount = 1;
        fp -> fId = id;
        if(pthread_mutex_init(&fp -> fLock, NULL) != 0){
            free(fp);
            return NULL;
        }

        idx = HASH(id);
        pthread_mutex_lock(&hashLock);
        fp -> fNext = fh[idx];
        fh[idx] = fp;
        pthread_mutex_lock(&fp -> fLock);
        pthread_mutex_unlock(&hashLock);
        pthread_mutex_unlock(&fp -> fLock);
    }

    return fp;
}


void fooHold(struct Foo *fp){
    pthread_mutex_lock(&hashLock);
    fp -> fCount ++;
    pthread_mutex_unlock(&hashLock);
}

struct Foo *fooFind(int id){
    struct Foo *fp;
    pthread_mutex_lock(&hashLock);
    for(fp = fh[HASH(id)]; fp != NULL; fp = fp -> fNext){
        if(fp -> fId = id){
            fp -> fCount ++;
            break;
        }
    }
    
    pthread_mutex_unlock(&hashLock);
    return fp;
}


void fooRele(struct Foo *fp){
    struct Foo *tfp;
    int idx;
    
    pthread_mutex_lock(&hashLock);
    if(-- fp -> fCount == 0){
        idx = HASH(fp -> fId);
        tfp = fh[idx];
        if(tfp == fp){
            fh[idx] = fp -> fNext;
        }else{
            while(tfp -> fNext != fp){
                tfp = tfp -> fNext;
            }
            tfp -> fNext = fp -> fNext;
        }
        pthread_mutex_unlock(&hashLock);
        pthread_mutex_destroy(&fp -> fLock);
        free(fp);
    }else{
        pthread_mutex_unlock(&hashLock);
    }
}

int main(int argc, const char *argv[])
{
    
    return 0;
}
