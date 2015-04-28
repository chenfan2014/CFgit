#include "dirent.h"
using namespace std;
int main(int argc, const char *argv[])
{
    const char *dPath;          //这里我们是对象是一个const对象，指向const对象的指针，如果写成char *const p;则是const指针

    char comm[20] = "";
    while(cin >> comm){
        if(strncmp(comm, "ls", 2) == 0){
            dPath = ".";
            my_ls(dPath);
        }else if(strncmp(comm, "cd", 2) == 0){
            
        }else if(strncmp(comm, "pwd", 3) == 0){
            my_pwd();
        }
    }
    return 0;
}
