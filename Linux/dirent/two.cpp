#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <fcntl.h>
using namespace std;
void setFl(int fd, int flags){
    int val;
    if((val = fcntl(fd, F_GETFL, 0)) < 0){
       cerr << "fcntl get error" << endl;               //获取文件描述符的状态
    }                   

    val  |= flags;                                  //设置我们的文件描述符状态值
    
    if(fcntl(fd, F_SETFL, val) < 0){                     //设置文件描述符给予新的状态
        cerr << "fcntl set error" << endl;
    }
}

void clrFl(int fd, int flags){
    int ival;
    if((ival = fcntl(fd, F_GETFL, 0)) < 0){
        cerr << "fcntl fd get error" << endl;
    }
    ival &= ~flags;

    if(fcntl(fd, F_SETFL, ival) < 0){
        cerr << "set fcntl error val" << endl;
    }
}
int main(int argc, const char *argv[])
{
    
    return 0;
}
