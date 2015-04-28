#include <iostream>
#include <string>
#include <vector>
#include "apue.h"
#include <ctype.h>
#include <fcntl.h>
#include <aio.h>
#include <errno.h>

const int BSZ = 4096;
const int NBUF = 8;

enum rwop{
    UNUSED = 0;
    READ_PENDING = 1,
    WRITE_PENDING = 2
};

struct buf{
    enum rwop op;
    int last;
    struct aiocb aiocb;
    unsigned char data[BSZ];
};

struct buf bufs[NBUF];

unsigned char translate(unsigned char c)
{
    if(c >= 'n'){
        c -= 13;
    }else if(c >= 'a'){
        c += 13;
    }else if(c >= 'N'){
        c -= 13;
    }else{
        c += 13;
    }
}

int main(int argc, const char *argv[])
{
    int ifd, ofd, i, j, n, err, nomop;
    struct stat sbuf;
    const struct aiocb *aiolist[NBUF];
    off_t off = 0;
    
    if(argc != 3){
        perror("wrong args");
    }
    
    if((ifd = open(argv[1], O_RDONLY)) < 0){
        perror("open failed");
    }
    if((ofd = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, FILE_MODE)) < 0){
        perror("create failed ");
    }
    if(fstat(ifd, &sbuf) < 0){
        perror("fstat failed");
    }

    for (int i = 0; i < NBUF; i++) {
        bufs[i].op = UNUSED;
        buf[i].aiocb.aio_buf = buf[i].data;
        buf[i].aiocb.aio_sigevent.sigev_notify = SIGEV_NONE;
        alolist[i] = NULL;
    }

    numop = 0;
    for(; ; ){
        for (i = 0; i < NBUF; i++) {
            switch(buf[i].op){
                case UNUSED:
                    if(off < sbuf.st_size){
                        bufs[i].op = READ_PENDING;
                        bufs[i].aiocb.aio_fildes = ifd;
                        bufs[i].aiocb.aio_offset = off;
                        off += BSZ;
                        
                        if(off > sbuf.st_size){
                            bufs[i].last = 1;
                        }

                        buf[i].aiocb,aio_nbytes = BSZ;

                        if(aio_read(&bufs[i].aiocb) < 0){
                            perror("aio_read error");
                        }

                        aiolist[i] = &bufs[i].aiocb;
                        numop ++;
                    }
                    break;

                case READ_PENDING:
                    if((err = aio_error(&bufs[i].aiocb)) == EINPROGRESS){
                        continue;
                    }
                    if(err != 0){
                        if(err == -1){
                            perror("aio_error failed");
                        }else{
                            perror("read failed");
                        }
                    }

                    if((n = aio_return(&bufs[i].aiocb)) < 0){
                        perror("return failed");
                    }

                    if(n != BSZ && !bufs[i].last){
                        
                    }
            }
        }
    }

    return 0;
}

