#include <iostream>
#include <string>
#include <vector>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)
int main(int argc, const char *argv[])
{
    if(argc != 2){
        ERR_EXIT("too few args");
    }

    if(access(argv[1], R_OK) < 0){
        ERR_EXIT("R_OK");
    }else{
        cout << "Yes R_OK" << endl;
    }
    
    if(access(argv[1], O_RDONLY) < 0){
        ERR_EXIT("O_RDONLY");
    }else{
        cout << "Yes O_RDONLY" << endl;
    }
    return 0;
}
