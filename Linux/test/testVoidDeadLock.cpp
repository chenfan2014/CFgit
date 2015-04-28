#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

using namespace std;
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

#define NHASH 29
#define HASH(id) (((unsigned long)id)%NHASH)

struct Foo *fh[NHASH];

pthread_mutex_t hashLock = PTHREAD_MUTEX_INITIALIZER;

struct Foo{
    int fCount;
    int fId;
    pthread_mutex_t fLock;
    struct Foo *fNext;
}

//分配对象
struct Foo *fooAlloc(int id){
    struct Foo *fp;
    int idx;

    if((fp = malloc(sizeof(struct Foo))) != NULL){
        fp -> fCount = 1;
        fp -> fId = id;
        
        if(pthread_mutex_init(&fp -> fLock, NULL) != 0){
            free(fp);
            return NULL;
        }

        idx = HASH(id);
        pthread_mutex_lock(&hashLock);
        fp -> fNext = fh[idx];
        pthread_mutex_lock(&fp -> lock);
        pthread_mutex_unlock(&hashLock);
        pthread_mutex_unlock(&fp -> lock);
    }
    return fp;
}

//添加一个对象的引用
void fooHold(struct Foo *fp){
    pthread_mutex_lock(fp -> fLock);
    fp -> fCount ++;
    pthread_mutex_unlock(fp -> fLock);
}

//查找一个存在的对象，并且对其调用fooHold函数
struct Foo *fooFind(int id){
    struct Foo *fp;

    pthread_mutex_lock(&hashLock);
    for(fp = fh[HASH(id)]; fp != NULL; fp = fp -> fNext){
        if(fp -> fId == id){
            fooHold(fp);
            break;
        }
    }
}

void fooRele(struct Foo *fp){
    struct Foo *tfp;
    int idx;
    
    pthread_mutex_lock(&fp -> fLock);
    if(fp -> fCount == 1){
        pthread_mutex_unlock(&fp -> fLock);
        pthread_mutex_lock(&hashLock);
        pthread_mutex_lock(&fp -> fLock);

        if(fp -> fCount != 1){
            fp -> fCount --;
            pthread_mutex_unlock(&fp -> fLock);
            pthread_mutex_unlock(&hashLock);
            return ;
        }

        idx = HASH(fp -> fId);
        tfp = fhp[idx];

        if(tfp == fp){
            fh[idx] = fp -> fNext;
        }else{
            while(tfp -> fNext != fp){
                tfp = tfp -> fNext;
            }
            tfp -> fNext = fp -> fNext;
        }
        pthread_mutex_unlock(&hashLock);
        pthread_mutex_unlock(&fp -> fLock);
        pthread_mutex_destroy(&fp -> fLock);
        free(fp);
    }else{
        fp -> fCount --;
        pthread_mutex_unlock(&fp -> fLock);
    }
}

int main(int argc, const char *argv[])
{
    
    return 0;
}
