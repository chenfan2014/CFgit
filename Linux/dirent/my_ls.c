#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)
int main(int argc, const char *argv[])
{
    DIR *dp;
    struct dirent *dirp;

    if(argc != 2){
        dp = opendir(".");      //.是当前目录
    }else{
        dp = opendir(argv[1]);
    }

    if(dp == NULL){
        ERR_EXIT("Wrong dir");
        exit(-1);
    }
    while((dirp = readdir(dp)) != NULL){
        if(strncmp(dirp -> d_name, ".", 1) != 0 && strncmp(dirp -> d_name, "..", 2) != 0){
            printf("%s ", dirp -> d_name);
        }
    }

    printf("\n");
    closedir(dp);
    return 0;
}
