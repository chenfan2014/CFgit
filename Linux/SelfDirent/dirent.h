#ifndef _DIRENT_H_
#define _DIRENT_H_ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
#include <vector>

#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <limits.h>

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

const int FILE_PATH_LEN = 100;

void my_ls(const char *);       //读取目录内容
void my_pwd();                  //获取当前路径

#endif  /*_DIRENT_H_*/
