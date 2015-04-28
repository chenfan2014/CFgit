#include <iostream>
#include <string>
#include <vector>
#include "apue.h"
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>

using namespace std;

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

static pid_t *childPid = NULL;
static int maxfd;

FILE *popen(const char *cmdstring, const char *type)
{
    int i;
    int pfd[2];
    pid_t pid;
    FILE *fp;

    if((type[0] != 'r' && type[0] != 'w') || type[1] != 0){     //非'r'和非'w'则返回出错
        errno = EINVAL;
        return NULL;
    }

    if(childPid == NULL){
        maxfd = 1024;
        if((childPid = (pid_t *)calloc(maxfd, sizeof (pid_t))) == NULL){
            return NULL;
        }
    }

    if(pipe(pfd) < 0){
        ERR_EXIT("error pipe");
    }

    if(pfd[0] >= maxfd || pfd[1] >= maxfd){
        close(pfd[0]);
        close(pfd[1]);
        errno = EMFILE;
        return NULL;
    }

    if((pid = fork()) < 0){
        ERR_EXIT("error fork");
    }else if(pid == 0){
        if(*type == 'r'){
            close(pfd[0]);
            if(pfd[1] != STDOUT_FILENO){
                dup2(pfd[1], STDOUT_FILENO);
                close(pfd[1]);
            }
        }
    }else{
        close(pfd[1]);
        if(pfd[0] != STDIN_FILENO){
            dup2(pfd[0], STDIN_FILENO);
            close(pfd[0]);
        }
    }

    for (i = 0; i < maxfd; i++) {
        if(childPid[i] > 0){
            close(i);
        }
        execl("/bin/sh", "sh", "-c", cmdstring, (char *)0);
        _exit(127);
    }

    if(*type == 'r'){
        close(pfd[1]);
        if((fp = fdopen(pfd[0], type)) == NULL){
            return NULL;
        }else{
            close(pfd[0]);
            if((fp = fdopen(pfd[1], type)) == NULL){
                return NULL;
            }
        }
    }

    childPid[fileno(fp)] = pid;
    return fp;

}


int pclose(FILE *fp)
{
    int fd, stat;
    pid_t pid;

    if(childPid == NULL){
        errno = EINVAL;
        return -1;
    }

    fd = fileno(fp);
    if(fd >= maxfd){
        errno = EINVAL;
        return -1;
    }

    if((pid = childPid[fd]) == 0){
        errno = EINVAL;
        return -1;
    }

    childPid[fd] = 0;
    if(fclose(fp) == EOF){
        return -1;
    }

    while(waitpid(pid, &stat, 0) < 0){
        if(errno != EINTR){
            return -1;
        }
    }

    return stat;
}

int main(int argc, const char *argv[])
{
    
    return 0;
}
