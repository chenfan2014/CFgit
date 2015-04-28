#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#define ERR_EXIT(m) \
    do{ \
        perror(m);  \
        exit(EXIT_FAILURE); \
    }while(0)
using namespace std;
int main(int argc, const char *argv[])
{
    DIR *dp;
    struct dirent *dirp;

    if(argc != 2){
        dp = opendir(".");
    }else{
        dp = opendir(argv[1]);
    }

    if(dp == NULL){
        ERR_EXIT("wrong dirent");
    }

    while((dirp = readdir(dp)) != NULL){
        if(strncmp(dirp -> d_name, ".", 1) != 0 && strncmp(dirp -> d_name, "..", 2) != 0 ){
            cout << dirp -> d_name << " ";
        }
    }
    cout << endl;
    closedir(dp);
    return 0;
}
