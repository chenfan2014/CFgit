#include <iostream>
#include <string>
#include <vector>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
using namespace std;
int main(int argc, const char *argv[])
{
    pid_t pid;
    int status;

    if((pid = fork()) < 0){
        cout << "error fork" << endl;
    }else if(pid == 0){
        exit(7);
    }
    if(wait(&status) != pid){
        cout << "wait error " << endl;
    }else{
        cout << "First time" << endl;
    }

    return 0; 
}
