#include <iostream>
#include <string>
#include <vector>

#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>



using namespace std;

int main(int argc, const char *argv[])
{
    int readFile = open("test.txt", O_RDONLY);
    if(readFile == -1){
        cout << "open failed" << endl;
    }
    char buf[10];
    off_t dis;
    size_t nread;
    memset(buf, 0, 10);
    while( (nread = read(readFile, buf, 10)) > 0){
        cout << buf << endl;
    }
    if((dis = lseek(readFile, 10, SEEK_END)) < 0){
        cout << "lseek" << endl;
    }else{
        cout << "Dis : " << dis << endl;
    }
    return 0;
}
