#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
using namespace std;
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)
int main(int argc, const char *argv[])
{
    char buf[1024] = " ";
    FILE *fp = popen("cat apue.h", "r");
    if(!fp){
        ERR_EXIT("popen error");
    }

    while(fgets(buf, 1024, fp) != NULL){
        cout << buf;
    }
    pclose(fp);
    return 0;
}
