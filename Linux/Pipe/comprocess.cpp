#include <iostream>
#include <string>
#include <vector>
#include "apue.h"
using namespace std;
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

int main(int argc, const char *argv[])
{
    int n, ival1, ival2;
    char line[1024] = " ";

    while((n = read(STDIN_FILENO, line, 1024)) > 0){
        line[n] = 0;
        if(sscanf(line, "%d%d", &ival1, &ival2) == 2){
            sprintf(line, "%d\n", ival1 + ival2);
            n = strlen(line);
            if(write(STDOUT_FILENO, line, n) != n){
                ERR_EXIT("write error");
            }
        }else{
            if(write(STDOUT_FILENO, "invaild args\n", 13) != 13){
                ERR_EXIT("write error");
            }
        }
    }
    return 0;
}
