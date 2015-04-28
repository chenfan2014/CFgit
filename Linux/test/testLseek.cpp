#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
using namespace std;
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)
int main(int argc, const char *argv[])
{
    int fd = open("seek.txt", O_RDWR | O_CREAT | O_TRUNC);
    int countSize;
    off_t seekSet;

    if(fd == -1){
        ERR_EXIT("error open file");
    }

    

    const char strWrite[] = "South China Normal University";
    int size = strlen(strWrite);
    if((countSize = (write(fd, strWrite, size))) != size){
        ERR_EXIT("write error");
    }

    seekSet = lseek(fd, 10, SEEK_END);

    if((countSize = (write(fd, strWrite, size))) != size){
        ERR_EXIT("write error");
    }
    
    close(fd);
    return 0;
}
