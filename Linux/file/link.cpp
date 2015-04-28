#include <iostream>
#include <string>
#include <vector>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
using namespace std;
int main(int argc, const char *argv[])
{
    int fd = open("test.txt", O_RDONLY);
    if(!fd){
        cout << "Wrong open" << endl;
    }
    cout << fd << endl;
    /*
    if(unlink("test.txt") < 0){
        cout << "unlink failed" << endl;
    }*/

    if(unlinkat(fd, "test.txt", AT_FDCWD) < 0){
        cout << "unlink failed" << endl;
    }


    cout << fd << endl;
    cout << "file unlinked " << endl;
    sleep(5);

    cout << "done" << endl;
    close(fd);
    return 0;
}
