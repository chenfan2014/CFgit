#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <stdlib.h>
using namespace std;
int main(int argc, const char *argv[])
{
    pid_t pid;
    
    cout << getpid() << " " << getppid() << endl;

    if((pid = fork()) < 0){
        cout << "error forkk" << endl;
    }else if(pid == 0){
        cout << "In child parent " << getpid() << " " << getppid() << endl;
        sleep(1);
    }else{
        cout << "parent progress" << endl;
    }
    
    cout << "outside : "<< getpid() << " " << getppid() << endl;

    return 0;
}
