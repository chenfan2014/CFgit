#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

pthread_t ptid;
void printTids(const char *s)
{
    pid_t pid;
    pthread_t  tid;

    pid = getpid();
    tid = pthread_self();

    printf("s = %s,  pid =  %lu,  tid =  %lu, tid = (0x%lx)\n", s, (unsigned long)pid, (unsigned long)tid, (unsigned long)tid);
}

void *thrFn(void *arg){
    printTids("new thread");
    return ((void *)0);
}

int main(int argc, const char *argv[])
{
    int err;

    err = pthread_create(&ptid, NULL, thrFn, NULL);
    if(err != 0){
        ERR_EXIT("can't create thread");
    }
    printTids("main thread");
    sleep(1);
 
    return 0;
}
