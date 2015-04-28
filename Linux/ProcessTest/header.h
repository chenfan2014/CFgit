#ifndef __HEADER_H__
#define __HEADER_H__ 

#include "NonCopyable.h"


#include <iostream>
#include <string>
#include <vector>

#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

const int BUFFERSIZE = 5;       //这个是我们生产的缓冲区大小

int Buffer = 0;           //Buffer=0意味着开始的时候我们缓冲区是没有东西的

void consumer(){
    Buffer --;
}

void producer(){
    Buffer ++;
}

#endif  /*__HEADER_H__*/
