#include "Rio.h"

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

Rio::Rio(int fd)
    :fd_(fd),
    left_(0),
    bufptr_(buffer_)
{   
}

ssize_t Rio::read(char *usrbuf, size_t n)       //判断是否可读
{
    ssize_t nread;
    while(left_ <= 0){
        nread = ::read(fd_, buffer_, sizeof buffer_);//从文件读数据督导buffer里面
        if(nread == -1){
            if(errno == EINTR){
                continue;
            }
            return -1;
        }else if(nread == 0){                        //没有数据可读
            return 0;
        }

        left_ = nread;                          //这里就是可读空间大小
        bufptr_ = buffer_;                      //下一次读数据的起始地址
    }
    
    int cnt = n;
    if(left_ < static_cast<int>(n)){            //这里意思是我们把缓冲区大小和设置的大小进行比较，如果开始空间太小了，则没问题，如果开始的空间设置的太大，那么我们的缓冲区大小以读入的数据为准
        cnt = left_;
    }
    ::memcpy(usrbuf, bufptr_, cnt);
    left_ -= cnt;                               //剩余可读空间
    bufptr_ += cnt;                             //剩余读取的起点

    return cnt; 
}

ssize_t Rio::readn(char *usrbuf, size_t n){
    size_t nleft = n;       //剩余可放置空间大小
    ssize_t nread;
    char *bufp = usrbuf;

    while(nleft > 0){       //还可以放东西
        if((nread = read(bufp, nleft)) == -1){  //设置缓冲区大小为nleft，读入数据放到bufp中
            return -1;
        }else if(nread == 0){
            break;
        }
        nleft -= nread;                         //如果没有读完的情况下，此时剩余空间的计算
        bufp += nread;                          //bufp计算的是我们的缓冲区存放数据的位置
    }
    return (n - nleft);     //读入的元素个数
}

ssize_t Rio::readline(char *usrbuf, size_t maxlen){
    char *bufp = usrbuf;
    ssize_t nread;
    char c;
    int i;
    
    for(i = 0; i != static_cast<int>(maxlen); i++){
        if((nread = read(&c, 1)) < 0){
            return -1;
        }else if(nread == 0){
            if(i == 0){
                return 0;
            }
            break;
        }
        *bufp++ = c;
        if(c == '\n'){      //当读到文件结尾的时候
            break;          
        }
    }
    *bufp = '\0';
    return i;
}


ssize_t Rio::writen(char *usrbuf, size_t n){
    size_t nleft;
    ssize_t nwrite;
    char *bufp = usrbuf;

    while(nleft > 0){
        if((nwrite = write(fd_, bufp, nleft)) <= 0){
            if(errno == EINTR){
                //continue;
                nwrite = 0;
            }else{
                return -1;
            }
        }
        nleft -= nwrite;
        bufp += nwrite;
    }
    return n;
}
