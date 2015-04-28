#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>     //用于_exit()
#include <stdlib.h>     //用于exit()
using namespace std;

int globval = 6;
char buf[] = "a write to stdout\n";

int main(int argc, const char *argv[])
{
    int val;
    pid_t pid;

    val = 88;
    if(write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1){
        cout << "write error" << endl;
    }

    cout << "Before fork " << endl;

    if((pid = vfork()) < 0){
        cout << "error fork" << endl;
    }else if(pid == 0){
        //cout << "son pid" << endl;
        globval ++;
        val ++;
        cout << "Son process " << endl;
        cout << getpid()  << " : " << getppid() << " : " << globval << " : " << val << endl;
        exit(0);       //这里一定要加上exit函数，否则会出现段错误
    }else{
        cout << "parent pid" << endl;
        //sleep(2);
    }

    cout << getpid()  << " : " << getppid() << " : " << globval << " : " << val << endl;

    return 0;
}
