#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
using namespace std;
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)
int main(int argc, const char *argv[])
{
    DIR *pDir;
    struct dirent *myent;
    int count = 0;
    if(argc == 1){
        pDir = opendir(".");
    }else{
        pDir = opendir(argv[1]);
    }
    if(pDir == NULL){
        ERR_EXIT("opendir failed");
        exit(-1);
    }
    while((myent = readdir(pDir)) != NULL){
        if(strncmp(myent -> d_name, ".", 1) != 0 && strncmp(myent -> d_name, "..", 2) != 0){
            cout << myent -> d_name << "  ";
            count ++;
            if(count % 5 == 0){
                cout << endl;
            }
        }
    }
    cout << endl;
    return 0;
}
