#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
using namespace std;
int main(int argc, const char *argv[])
{
    int fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC);
    int cnt;
    char buf[10] = "hinaSouth";

    if(write(fd, buf, 10) < 0){
        cerr << "Wrong write" << endl;
    }

    if(lseek(fd, 4096, SEEK_SET) == -1){
        cerr << "lseek error" << endl;
    }

    if(write(fd, "  Beijing", strlen("  Beijing")) < 0){
        cerr << "write error" << endl;
    }

    close(fd);
    return 0;
}
