#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std;

static void charataTime(char *str){
    char *ptr;
    int c;

    setbuf(stdout, NULL);
    for(ptr = str; (c = *ptr ++) != 0; ){
        putc(c, stdout);
    }
    cout << endl;
}

int main(int argc, const char *argv[])
{
    pid_t pid;
    
    if((pid = fork()) < 0){
        cout << "err fork " << endl;
    }else if(pid == 0){
        charataTime("output from child\n");
    }else{
        charataTime("output from parent\n");
    }

    return 0;
}
