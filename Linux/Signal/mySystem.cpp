#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
int system(const char *cmdString)
{
    pid_t pid;
    int status;
    struct sigaction ignore, saveIntr, saveQuit;
    sigset_t clidMask, saveMask;

    if(cmdString == NULL){
        return 1;
    }

    ignore.sa_handler = SIG_IGN;
    sigemptyset(&ignore.sa_mask);
    ignore.sa_flags = 0;

    if(sigaction(SIGINT, &ignore, &saveIntr) < 0){
        return -1;
    }

    if(sigaction(SIGQUIT, &ignore, &saveIntr) < 0){
        return -1;
    }

    sigemptyset(&clidMask);
    sigaddset(&clidMask, SIGCHLD);
    if(sigprocmask(SIG_BLOCK, &clidMask, &saveIntr) < 0){
        return -1;
    }
    
    if((pid = fork()) < 0){
        status = -1;
    }else if(pid == 0){
        sigaction(SIGINT, &saveIntr, NULL);
        sigaction(SIGQUIT, &saveQuit, NULL);
        sigprocmask(SIG_SETMASK, &saveMask, NULL);

        execl("bin/sh", "sh", "-c", cmdstring, (char *)0);
        _exit(127);
    }
}else{
    while(waitpid(pid, &status, 0) < 0){
        if(errno != EINTR){
            status = -1;
            break;
        }
    }
    
    if(sigaction(SIGINT, &saveIntr, NULL) < 0){
        return -1
    }

    if(sigaction(SIGQUIT, &saveQuit, NULL) < 0){
        return -1;
    }

    if(sigprocmask(SIG_SETMASK, &saveMask, NULL) < 0){
        return -1;
    }
    

    return status;
}
