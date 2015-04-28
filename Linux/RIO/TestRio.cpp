#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
using namespace std;

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

ssize_t readn(int fd, char *usrbuf, size_t n)
{
    size_t nleft = n;
    ssize_t nread;
    //char *bufp = usrbuf;

    while(nleft > 0){
        if((nread = read(fd, usrbuf, nleft)) < 0){
            if(nread == -1){
                if(errno == EINTR){
                    continue;
                }
                return -1;
            }else if(nread == 0){
                break; 
            }
        }
        
        usrbuf += nread;
        nleft -= nread;
    }
    return (n - nleft);
}

ssize_t writen(int fd, char *usrbuf, size_t n)
{
    size_t nleft = n;
    ssize_t nwrite;
    
    while(nleft > 0){
        if((nwrite = write(fd, usrbuf, nleft)) < 0){
            if(nwrite == -1){
                if(errno == EINTR){
                    continue;
                }
                return -1;
            }else if(nwrite == 0){
                break;
            }
        }
    }
}

int main(int argc, const char *argv[])
{
    
    return 0;
}
