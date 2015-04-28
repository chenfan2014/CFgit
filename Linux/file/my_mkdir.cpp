#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <sys/stat.h>
using namespace std;
int main(int argc, const char *argv[])
{
    if(mkdir("dirone", 0777) < 0){
        cout << "error made one" << endl;
    }
    if(mkdir("dirtwo", 0777) < 0){
        cout << "error made two" << endl;
    }
    if(rmdir("dirone") < 0){
        cout << "rmdir failed" << endl;
    }
    if(rmdir("dirtwo") < 0){
        cout << "rmdir failed" << endl;
    }

    return 0;
}
