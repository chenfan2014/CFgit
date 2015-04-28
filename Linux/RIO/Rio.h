#ifndef __RIO_R__
#define __RIO_R__ 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "NonCopyable.h"

const int RIOBUFFER = 8192;
const int MAXLINE = 1024;

class Rio : public NonCopyable{
    public:
        explicit Rio(int fd);

        ssize_t readn(char *usrbuf, size_t n);
        ssize_t writen(char *usrbuf, size_t n);
        ssize_t readline(char *usrbuf, size_t maxlen);
    private:
        ssize_t read(char *usrbuf, size_t n);

        int fd_;
        int left_;
        char *bufptr_;
        char buffer_[RIOBUFFER];
};

#endif  /*__RIO_R__*/
