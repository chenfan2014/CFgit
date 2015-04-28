#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
using namespace std;
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)
int main(int argc, const char *argv[])
{
    time_t t;
    struct tm *tmp;
    char buf1[16];
    char buf2[64];

    time(&t);
    tmp = localtime(&t);        //这句话是获取我们的时间，然后通过strftime函数把时间转化成一个格式

    if(strftime(buf1, 16, "time and data : %r, %a %b %d, %y", tmp) == 0){
        //ERR_EXIT("16 is too less");
        cout << "16 is too less " << endl;
    }else{
        cout << buf1 << endl;
    }
    
    if(strftime(buf2, 64, "time and data : %R, %A %B %D, %Y", tmp) == 0){
        ERR_EXIT("64 is too less");
    }else{
        cout << buf2 << endl;
    }
    return 0;
}
