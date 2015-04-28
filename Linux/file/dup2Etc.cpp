#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
using namespace std;
int main(int argc, const char *argv[])
{
    int oldfd = open("test.txt", O_RDONLY);
    int newfd;
    char buf[1024] = "";
    int nread;
    int iret;
    if((iret = dup2(oldfd, newfd)) == -1){
        cout << "error dup2" << endl;
    }else{
        cout << "O : " << oldfd << " N : " << newfd << endl;
        while((nread = read(newfd, buf, 1024)) > 0){
            write(1, buf, nread);
        }
    }
    cout << newfd << " " << oldfd << endl;
    close(oldfd);
    close(newfd);
    return 0;
}
