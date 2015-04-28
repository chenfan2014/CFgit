#include <iostream>
#include <string>
#include <vector>
#include <pthread.h>
#include <stdlib.h>

class foo{
    public:
        int fCount_;
        pthread_mutex_t fLock_;
        int fId_;
};

foo *fooAlloc(int id){
    foo *fp;

    if((fp = malloc(sizeof(foo))) != NULL){
        fp -> fCount_ = 1;
        fp -> fId_ = id;
        
        if(pthread_mutex_init(&fp -> fLock_, NULL) != 0){
            free(fp);
            return NULL;
        }
    }
    return fp;
}

void fooHold(foo *fp){
    pthread_mutex_lock(&fp -> fLock_);
    fp -> fCount_ ++;
    pthread_mutex_unlock(&fp -> fLock_);
}

void fooRele(foo *fp){
    pthread_mutex_lock(&fp -> fLock_);
    if(-- fp -> fCount_ == 0){
        pthread_mutex_unlock(&fp -> fLock_);
        pthread_mutex_destroy(&fp -> fLock_);
        free(fp);
    }else{
        pthread_mutex_unlock(&fp -> fLock_);
    }

}
