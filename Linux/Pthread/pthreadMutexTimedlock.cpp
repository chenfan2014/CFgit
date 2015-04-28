#include <iostream>
#include <string>
#include <vector>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

/*
 *此程序演示了用pthread_mutex_timedlock避免永久阻塞
 *
 */

int main(int argc, const char *argv[])
{
    int err;
    struct timespec timeOut;
    struct tm *tmp;
    char buf[64];
    memset(buf, 0, 64);
    pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

    pthread_mutex_lock(&lock);
    cout << "mutex is locked" << endl;
    clock_gettime(CLOCK_REALTIME, &timeOut);
    tmp = localtime(&timeOut.tv_sec);
    strftime(buf, sizeof(buf), "%r", tmp);
    cout << "current time is " << buf << endl;
    timeOut.tv_sec += 10;

    err = pthread_mutex_timedlock(&lock, &timeOut);
    //pthread_mutex_unlock(&lock);
    clock_gettime(CLOCK_REALTIME, &timeOut);
    tmp = localtime(&timeOut.tv_sec);
    strftime(buf, sizeof(buf), "%r", tmp);
    cout << "the time is now : " << buf << endl;

    if(err == 0){
        cout << "mutex locked again" << endl;
    }else{
        cout << "can not lock again" << endl;
    }

    return 0;
}
