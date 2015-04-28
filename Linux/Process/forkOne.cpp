#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main(int argc, const char *argv[])
{
    pid_t ppid;

    if((ppid = fork()) > 0){
        cout << ppid << " : This is the father process" << endl;
        exit(0);
    }else if((ppid = fork())= 0){
        cout << ppid << " : This is the son process" << endl;
        exit(0);
    }


    return 0;
}
