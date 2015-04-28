#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)
int main(int argc, const char *argv[])
{
    const char buf1[] = "China";
    const char buf2[] = "Easten";

    int fd;
    //if((fd = open("lseek.txt", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH))== -1){
    //    ERR_EXIT("open failed");
    //}

    if((fd = creat("lseek.txt", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1){
        ERR_EXIT("error create");
    }

    if(write(fd, buf1, 5) != 5){
        ERR_EXIT("write error");
    }

    if(lseek(fd, 16384, SEEK_SET) == -1){
        ERR_EXIT("write kongdong error");
    }

    if(write(fd, buf2, 6) != 6){
        ERR_EXIT("error write easten");
    }
    close(fd);
    return 0;
}
