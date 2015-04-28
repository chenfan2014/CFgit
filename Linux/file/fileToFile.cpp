#include <iostream>
#include <string>
#include <vector>
#include <string.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
using namespace std;
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)
int main(int argc, const char *argv[])
{
    int fd = open("test.txt", O_RDONLY);
    if(!fd){
        ERR_EXIT("open read failed");
    }
    int outFd = open("test2.txt", O_WRONLY | O_CREAT | O_TRUNC);
    if(!outFd){
        ERR_EXIT("open write failed");
    }
    char str[1024];
    int nread;
    memset(str, 0, 1024);
    while( (nread = read(fd, str, 1024)) > 0){
        cout << "in" << endl;
        write(outFd, str, nread);
    }
    close(fd);
    close(outFd);
    return 0;
}

