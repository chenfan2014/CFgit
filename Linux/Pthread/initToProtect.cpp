#include "apue.h"
#include <iostream>
#include <string>
#include <vector>
#include <syslog.h>
#include <fcntl.h>
#include <sys/resource.h>

using namespace std;

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)


void daemonize(const char *cmd)
{
    int i, fdZero, fdOne, fdTwo;
    pid_t pid;
    struct rlimit rl;
    struct sigaction sa;

    umask(0);                               //第一步，设置umask屏蔽字。一般设为0
    
    if(getrlimit(RLIMIT_NOFILE, &rl) < 0){  //获取文件描述符最大值
        ERR_EXIT("can not get file limit");        
    }
   

    if((pid = fork()) < 0){                 //使进程没有控制终端（TTY）
        ERR_EXIT("fork err");
    }else if(pid != 0){
        exit(0);
    }

    setsid();                               //创建一个新的会话    
    
    sa.sa_handler = SIG_IGN;                //确认打开无法占用控制终端
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if(sigaction(SIGHUP, &sa, NULL) < 0){
        ERR_EXIT("err sigaction");
    }
        
    if((pid = fork()) < 0){
        ERR_EXIT("err fork");
    }else if(pid != 0){
        exit(0);
    }
    
    if(chdir("/") < 0){                     //更改工作目录
        ERR_EXIT("change dir err");
    }
    
    if(rl.rlim_max == RLIM_INFINITY){       //关闭所有的文件描述符
        rl.rlim_max = 1024;
    }
    for(i = 0; i < rl.rlim_max; i ++){
        close(i);
    }
    
    fdZero = open("/dev/null", O_RDWR);     //把文件描述符0,1,2重定向到/dev/null
    fdOne = dup(0);
    fdTwo = dup(0);

    
    openlog(cmd, LOG_CONS, LOG_DAEMON);     //初始化 log file
    if(fdZero != 0 || fdOne != 1 || fdTwo != 2){
        syslog(LOG_ERR, "unexpect file descriptions %d %d %d", fdZero, fdOne, fdTwo);
        exit(1);
    }

}

int main(int argc, const char *argv[])
{
    daemonize("beijing");
    sleep(120);
    return 0;
}
