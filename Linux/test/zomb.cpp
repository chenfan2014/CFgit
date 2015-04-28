#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

using namespace std;
int main(int argc, const char *argv[])
{
    pid_t pid;

    if((pid = fork()) < 0){
        cerr << "fork error" << endl;
    }else if(pid == 0){
        sleep(1);
        cout << getppid() << endl;
        exit(0);
    }else{
        cout << getpid() << endl;
        exit(0);
    }
    return 0;
}
