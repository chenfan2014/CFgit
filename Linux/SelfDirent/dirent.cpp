#include "dirent.h"
#include <dirent.h>
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <unistd.h>
using namespace std;
void my_ls(const char *path){
    DIR *dp;
    struct dirent *dirp;                        //用来存储我们读取目录的内容

    if((dp = opendir(path)) == 0){              //打开文件目录
        ERR_EXIT("wrong path to opendir");
    }

    while((dirp = readdir(dp)) != NULL){
        if(strncmp(dirp -> d_name, ".", 1) != 0 && strncmp(dirp -> d_name, "..", 2) != 0){
            std::cout << dirp -> d_name << " ";      //判断我们读到的目录文件名是否为.以及..，如果是则不输出，否则输出
        }
    }
    cout << endl;
    closedir(dp);
}

void my_pwd(){                                  //获取当前路径
    char *path;             
    size_t size = FILE_PATH_LEN;                //函数有两个参数，第一个是我们存放我们取得的路径
    path = (char *)malloc(size);                //第二个是我们路径长度大小的值的设定，然后动态分配内存
    
    if(getcwd(path, size) == NULL){
        ERR_EXIT("error getcwd");
    }
    
    cout << path << endl;
}
