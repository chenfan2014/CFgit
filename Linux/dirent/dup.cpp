#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)
int main(int argc, const char *argv[])
{
    int newfd = dup(1);
    int n;
    char buf[4096];
    if((n = read(STDIN_FILENO, buf, 4096)) > 0){
        if(write(newfd, buf, n) != n){
            ERR_EXIT("error write");
        }
    }
      
    dup2(0, newfd);

    if((n = read(newfd, buf, 4096)) > 0){
        if(write(STDOUT_FILENO, buf, n) != n){
            ERR_EXIT("error STDOUT_FILENO");
        }
    }

    return 0;
}
