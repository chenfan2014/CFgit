#ifndef __THREAD_SAFE
#define __THREAD_SAFE 
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <pthread.h>

class Counter{
    public:
        Counter()
            :value_(0)
        {}

        int64_t value() const;
        int64_t getAndIncrease();

    private:
        int64_t value_;
        mutable MutexLock lock_;
};

int64_t Counter::value() const{
    MutexLockGuand lock(mutex_);
    return ret;
}

int64_t Counter::getAndIncrease(){
    MutexLockGuard lock(mutex_);
    int64_t ret = value++;
    return ret;
}
#endif  /*__THREAD_SAFE*/
