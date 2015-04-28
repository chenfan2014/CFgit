#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
using namespace std;
#define ERR_EXIT(m) \
    do{ \
        perror(m);  \
        exit(EXIT_FAILURE); \
    }while(0)

#if defined(MACOS)
#include <sys/syslimits.h>
#elif defined(SOLARIS)
#include <limits.h>
#elif defined(BSD)
#include <sys/param.h>
#endif

unsigned long long count;
struct timeval end;

void checkTime(char *str){
    struct timeval tv;

    gettimeofday(&tv, NULL);

    if(tv.tv_sec >= end.tv_sec && tv.tv_usec >= end.tv_usec){
        cout << str << "  count  =  " << count << endl;
        exit(0);        //#include <stdlib.h>
    }
}

int main(int argc, const char *argv[])
{
    pid_t pid;
    char *s;
    int nzero, ret;
    int adj = 0;

    setbuf(stdout, NULL);       //i设置输出为无缓冲

#if defined(NZERO)
    nzero = NZERO
#elif defined(_SC_NZERO)
    nzero = sysconf(_SC_NZERO);
#else
#error NZERO undefined
#endif

    cout << "NZERO = " << nzero << endl;
    if(argc == 2){
        adj = strtol(argv[1], NULL, 10);
    }

    gettimeofday(&end, NULL);
    end.tv_sec += 10;           //运行十秒

    if((pid = fork()) < 0){
        ERR_EXIT("fork error");
    }else if(pid == 0){
        s = "child";
        cout << "Current nice value in child is " << nice(0) + nzero << "  , adjusting by " << adj << endl;
        errno = 0;
        if((ret = nice(adj)) == -1 && errno != 0){
            ERR_EXIT("child set scheduling priority");
        }
        cout << "Now child nice value is " << ret + nzero << endl;
    }else{
        s = "parent";
        cout << "Current nice value in parents is " << nice(0) + nzero << endl;
    }
    for(; ; ){
        if(++ count == 0){
            ERR_EXIT("count wrap");
        }
        checkTime("s");
    }
    return 0;
}
