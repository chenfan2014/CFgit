#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
using namespace std;
int main(int argc, const char *argv[])
{
    if(rename("test.txt", "test.txt") < 0){
        cout << "can not rename of file" << endl;
    }else{
        cout << "rename file success" << endl;
    }

    if(rename("kdir", "dir") < 0){
        cout << "can not rename dir" << endl;
    }else{
        cout << "rename dir success " << endl;
    }

        
    return 0;
}
