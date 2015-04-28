#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
using namespace std;
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

void printDir(char *dir, int depth)
{
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
    
    if((dp = opendir(dir)) == NULL){
        cout << "NULL : " << dir << endl;
        ERR_EXIT("opendir");
    }

    while((entry = readdir(dp)) != NULL){
        lstat(entry -> d_name, &statbuf);
        if(S_ISDIR(statbuf.st_mode)){
            if(strcmp(".", entry -> d_name) == 0 || strcmp("..", entry -> d_name) == 0){
                continue;
            }
            printf("%*s%s/\n", depth, "", entry -> d_name);
            printDir(entry -> d_name, depth + 4);
        }else{
            printf("%*s%s/\n", depth, "", entry -> d_name);
        }
    }
    chdir("..");
    closedir(dp);
}
int main(int argc, const char *argv[])
{
    char path[100] = " ";
    cout << "Please input the path to search : ";
    cin >> path;
    printDir(path, 0);
    cout << "Done" << endl;
    return 0;
}
