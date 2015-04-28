#include <time.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <errno.h>
#include <string.h>
using namespace std;
int main(int argc, const char *argv[])
{
    int err;
    struct timespec timeOut;
    struct tm *tmp;
    char buf[64];
    pthread_mutex_t timeLock = PTHREAD_MUTEX_INITIALIZER;

    pthread_mutex_lock(&timeLock);
    cout << "Mutex is locked" << endl;

    clock_gettime(CLOCK_REALTIME, &timeOut);
    tmp = localtime(&timeOut.tv_sec);
    strftime(buf, sizeof(buf),  "%r", tmp);
    cout << "Current time is " << buf << endl;

    timeOut.tv_sec += 10;
    err = pthread_mutex_timedlock(&timeLock, &timeOut);
    clock_gettime(CLOCK_REALTIME, &timeOut);
    tmp = localtime(&timeOut.tv_sec);
    strftime(buf, sizeof(buf), "%r", tmp);
    cout << "The time is now " << buf << endl;

    if(err == 0){
        cout << "Mutex Lock again" << endl;
    }else{
        cout << "Can not lock again" << strerror(err) << endl;
    }
    return 0;
}
