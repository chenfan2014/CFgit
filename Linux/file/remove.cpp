#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
using namespace std;
int main(int argc, const char *argv[])
{
    remove("test.txt");
    int fd;
    if((fd = open("test.txt", O_RDONLY)) < 0){
        cout << "remove success" << endl;
    }else{
        cout << "remove failed" << endl;
    }
    return 0;
}
