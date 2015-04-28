#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <syslog.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <sys/stat.h>
#include <iostream>

using namespace std;

const string LOCKFILE = "/var/run/daemon.pid";
#define LOCKMODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

extern int lockfile(int);

int alreadyRunning(void)
{
    int fd;
    char buf[16] = " ";

    if((fd = open(LOCKFILE.c_str(), O_RDWR | O_CREAT, LOCKMODE)) < 0){
        syslog(LOG_ERR, "can not open file");
    }

    if(lockfile(fd) < 0){
        if(errno == EACCES || errno == EAGAIN){
            close(fd);
            return 1;
        }
        syslog(LOG_ERR, "can not lock this");
        exit(1);
    }
    
    ftruncate(fd, 0);
    sprintf(buf, "%ld", (long)getpid());
    write(fd, buf, strlen(buf) + 1);
    return 0;
}

int main(int argc, const char *argv[])
{
    
    return 0;
}
