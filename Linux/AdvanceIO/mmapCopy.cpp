#include "apue.h"
#include <sys/mman.h>
#include <fcntl.h>
using namespace std;

const int COPYINCR = 1024*1024*1024;

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

int main(int argc, const char *argv[])
{
    int fdin, fdout;
    void *src, *dst;
    size_t copysz;
    struct stat sbuf;
    off_t fsz = 0;

    if(argc != 3){
        ERR_EXIT("err args");
    }

    if((fdin = open(argv[1], O_RDONLY)) < 0){
        ERR_EXIT("err open");
    }

    if((fdout = open(argv[2], O_RDWR | O_CREAT | O_TRUNC)) < 0){
        ERR_EXIT("err create");
    }

    if(fstat(fdin, &sbuf) < 0){
        ERR_EXIT("fstat err");
    }

    if(ftruncate(fdout, sbuf.st_size) < 0){
        ERR_EXIT("ftruncate err");
    }

    while(fsz < sbuf.st_size){
        if((sbuf.st_size - fsz) < COPYINCR){
            copysz = COPYINCR;
        }else{
            copysz = sbuf.st_size - fsz;
        }


        if((src = mmap(0, copysz, PROT_READ, MAP_SHARED, fdin, fsz)) == MAP_FAILED){
            ERR_EXIT("err mmap");
        }

        if((dst = mmap(0, copysz, PROT_READ  | PROT_WRITE, MAP_SHARED, fdout, fsz)) == MAP_FAILED){
            ERR_EXIT("err mmap out");
        }

        memcpy(dst, src, copysz);
        munmap(src, copysz);
        munmap(dst, copysz);
        fsz += copysz;
    }
    return 0;
}
