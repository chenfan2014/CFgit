#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)
int main(int argc, const char *argv[])
{
    int iret;
    if(argc == 1){
        ERR_EXIT("too few args");
    }else{
        iret = mkdir(argv[1], 0777);
    }
    return 0;
}
