#include <iostream>
#include <string>
#include <vector>
#include <errno.h>
#include <fcntl.h>
#include "apue.h"

using namespace std;

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

char buf[500000];

void set_fl(int fd, int flags){
    int val;
    if((val = fcntl(fd, F_GETFL, 0)) < 0){  //F_GETFL测试能否建立一把锁
        ERR_EXIT("set_fl fcntl get");
    }

    val |= flags;
    if(fcntl(fd, F_SETFL, val) < 0){        //F_SETFL建立锁,如果不希望等待锁为可用的时候，就处理可能的出错
        ERR_EXIT("set_fl fcntl set");
    }
}

void clr_fl(int fd, int flags){
    int val;

    if((val = fcntl(fd, F_GETFL, 0)) < 0){
        ERR_EXIT("clr_fl fcntl get");
    }
    val &= ~flags;

    if(fcntl(fd, F_SETFL, 0) < 0){
        ERR_EXIT("clr_fl fcntl set");
    }
}


int main(int argc, const char *argv[])
{
    int ntoWrite, nWrite;
    char *ptr;

    if((ntoWrite = read(STDIN_FILENO, buf, sizeof buf)) < 0){
        ERR_EXIT("read failed");
    }
    fprintf(stderr, "read %d bytes \n", ntoWrite);

    set_fl(STDOUT_FILENO, O_NONBLOCK);

    ptr = buf;
    while(ntoWrite > 0){
        errno = 0;
        nWrite = write(STDOUT_FILENO, ptr, ntoWrite);
        fprintf(stderr, "nWrite = %d, errno = %d\n, ", nWrite, errno);
    
        cout << endl;

        if(nWrite > 0){
            ptr += nWrite;
            ntoWrite -= nWrite;
        }
    }
    clr_fl(STDOUT_FILENO, O_NONBLOCK);

    return 0;
}
