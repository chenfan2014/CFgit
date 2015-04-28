#include <iostream>
#include <string>
#include <vector>
#include "apue.h"
#include <fcntl.h>
#include <ctype.h>
using namespace std;
const int BSZ = 1024;
unsigned char buf[BSZ];
unsigned char translate(unsigned char c)
{
    if(isalpha(c)){
        if(c >= 'n'){
            c -= 13;
        }else if(c >= 'a'){
            c += 13;
        }else if(c >= 'N'){
            c -= 13;
        }else{
            c +=13;
        }
    }

    return c;
}

int main(int argc, const char *argv[])
{
    int ifd, ofd, i, n, nw;
    if(argc != 3){
        perror("too few args");
    }

    if((ifd = open(argv[1], O_RDONLY)) < 0){
        perror("open failed");
    }

    if((ofd = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, FILE_MODE)) < 0){
        perror("create failed");
    }

    while((n = read(ifd, buf, BSZ)) > 0){
        for (int i = 0; i < n; i++) {
            buf[i] = translate(buf[i]);
        }

        if((nw = write(ofd, buf, n)) != n){
            if(nw < 0){
                perror("write failed");
            }else{
                perror("short write");
            }
        }

    }
    fsync(ofd);
    return 0;
}
