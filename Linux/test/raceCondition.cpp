#include "apue.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define ERR_EXIT(m) \
    do{ \
        perror(m);  \
        exit(EXIT_FAILURE); \
    }while(0)

static void charatatime(char *);
int main(int argc, const char *argv[])
{
    pid_t pid;
    if((pid = fork()) < 0){
        ERR_EXIT("fork error");
    }else if(pid == 0){
        charatatime("1234567890\n312413123\n321fajkfda\nfdajgjkajfdoa\n");
    }else{
        charatatime("south\n china \n ormal\nunviersity\n");
    }
    return 0;
}

static  void charatatime(char *str){
    char *ptr;
    int c;

    //setbuf(stdout, NULL);
    for(ptr = str; c = *ptr; ptr ++){
        putc(c, stdout);
    }
    /*
     * 这里我们先运行赋值运算，等到赋值完了以后我们再运行++操作哦
     * 这里我们循环结束的条件是我们碰到了结束符号也就是没有任何的符号了
    for(ptr = str; (c = *ptr ++) != 0; ){
        putc(c, stdout);
    }
    */
}
