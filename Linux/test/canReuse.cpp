#include <iostream>
#include <pwd.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
using namespace std;
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

static void myAlarm(int signo){
    struct passwd *rootPtr;
    cout << "In signal handler " << endl;
    if((rootPtr = getpwnam("root")) == NULL){   //getpwnam是非可重入函数
        ERR_EXIT("error getpwnam(root) ");
    }
    alarm(1);           //一秒钟产生一次SIGALRM信号
}

int main(int argc, const char *argv[])
{
    struct passwd *ptr;

    signal(SIGALRM, myAlarm);       //处理SIGALRM信号
    alarm(1);

    for( ; ;){
        if((ptr = getpwnam("sar")) == NULL){
            ERR_EXIT("getpwnam error");
        }
        if(strcmp(ptr -> pw_name, "sar") != 0){
            cout << "return value corrupted , pw_name = " << ptr -> pw_name << endl;
        }
    }
    return 0;
}
