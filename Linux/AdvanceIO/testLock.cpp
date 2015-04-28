#include <iostream>
#include <string>
#include <vector>
#include <fcntl.h>
#include "apue.h"
using namespace std;

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

pid_t lockTest(int fd, int type, off_t offset, int whence, off_t len)
{
    struct flock lock;
    lock.l_type = type;
    lock.l_start = offset;
    lock.l_whence = whence;
    lock.l_len = len;

    if(fcntl(fd, F_GETLK, &lock) < 0){
        ERR_EXIT("fcntl error ");
    }

    if(lock.l_type == F_UNLCK){
        ERR_EXIT("false to add lock");
    }else{
        return lock.l_pid;
    }
}

int main(int argc, const char *argv[])
{
    pid_t testPid;
    
    return 0;
}
