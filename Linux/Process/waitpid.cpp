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
    cout << "pid = : " << getppid()  << endl; 
    if((pid = fork()) < 0){
        cout << "fork first error " << endl;
    }else if(pid == 0){
        cout << "pid = : " << getpid()  << " " << getppid() << endl;
        if((pid = fork()) < 0){
            cout << "fork second error " << endl;
        }else if(pid > 0){
            cout << "pid > 0" << endl;
            exit(0);
        }
        sleep(2);
        cout << "second child, parent pid  : " << getppid() << endl;
        exit(0);
    }

    if(waitpid(pid, NULL, 0) != pid){
        cout << "error waitpid" << endl;
    }

    return 0;
}
