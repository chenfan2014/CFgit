#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <sys/types.h>
using namespace std;
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)
int main(int argc, const char *argv[])
{
    int res = -1;
    int fd[2];
    int nBytes;
    pid_t pid;
    char str[] = "South China Normal University\n";
    char readBuffer[80];
    memset(readBuffer, 0, 80);
    int readfd = fd[0];
    int writefd = fd[1];

    if((res = pipe(fd)) == -1){
        cout << "pipe error" << endl;
    }
    if((pid = fork()) == -1){
        ERR_EXIT("fork error");
    }else if(pid == 0){     //child
        close(readfd);
        res = write(writefd, str, strlen(str));
        return 0;
    }else{
        close(writefd);
        nBytes = read(readfd, readBuffer, sizeof(readBuffer));
        cout << "Receivve : " << readBuffer << endl;
    }
    return 0;
}
