#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>
using namespace std;
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)
int main(int argc, const char *argv[])
{
    int i;
    struct stat buf;
    char *ptr;

    for(i = 1; i != argc; i ++){
        cout << "argv[" << i << "]  =  " << argv[i] <<  " ";
        if(lstat(argv[i], &buf)){
            ERR_EXIT("lstat error");
            continue;
        }

        if(S_ISREG(buf.st_mode)){
            ptr = "普通文件";
        }else if(S_ISDIR(buf.st_mode)){
            ptr = "目录文件";
        }else if(S_ISCHR(buf.st_mode)){
            ptr = "字符文件";
        }else if(S_ISFIFO(buf.st_mode)){
            ptr = "管道文件";
        }else if(S_ISBLK(buf.st_mode)){
            ptr = "块文件";
        }else if(S_ISLNK(buf.st_mode)){
            ptr = "符号链接";
        }else if(S_ISSOCK(buf.st_mode)){
            ptr = "套接字";
        }else{
            ptr = "Unknown file type";
        }
        cout << ptr << endl;
    }
    return 0;
}
