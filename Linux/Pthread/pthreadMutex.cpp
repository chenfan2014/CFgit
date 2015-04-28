#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

struct Foo{
    int fCount;
    pthread_mutex_t fLock;
    int fId;
};



struct Foo *fooAlloc(int id){
    struct Foo *fp;

    if((fp = (Foo *)malloc(sizeof(struct Foo))) != NULL){
        fp -> fCount = 1;
        fp -> fId = id;
        if(pthread_mutex_init(&fp -> fLock, NULL) != 0){
            free(fp);
            return NULL;
            //ERR_EXIT("pthread_mutex_init");
        }
    }
    return fp;
}

void fooHold(struct Foo *fp){       //这是一个加锁然后进行信息处理再解锁的过程
    pthread_mutex_lock(&fp -> fLock);
    fp -> fCount ++;
    pthread_mutex_unlock(&fp -> fLock);
}

void fooRele(struct Foo *fp){
    pthread_mutex_lock(&fp -> fLock);
    if((-- fp -> fCount) == 0){
        pthread_mutex_unlock(&fp -> fLock);
        pthread_mutex_destroy(&fp -> fLock);
        free(fp);
    }else{
        pthread_mutex_unlock(&fp -> fLock);
    }
}

int main(int argc, const char *argv[])
{
    
    return 0;
}
