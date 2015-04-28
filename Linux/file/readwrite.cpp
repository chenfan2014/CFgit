#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#define BUFFERSIZE 1024
using namespace std;
int main(int argc, const char *argv[])
{
    char buf[BUFFERSIZE];
    memset(buf, 0, BUFFERSIZE);
    int nread;
    while((nread = read(STDIN_FILENO, buf, BUFFERSIZE)) > 0){
        write(STDOUT_FILENO, buf, sizeof(buf));
    }
    return 0;
}
