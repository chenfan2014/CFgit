#include <iostream>
#include <string>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>      //open

#include <unistd.h>     //read

using namespace std;
int main(int argc, const char *argv[])
{
    int fd = open("test.txt", O_WRONLY | O_CREAT);
    //string s = "beijing";
    char s[] = "beijing";
    write(fd, s, strlen(s));
    close(fd);

    fd = open("test.txt", O_RDONLY);
    char str[100] = " ";
    read(fd, str, strlen(s));
    cout << str << endl;
    close(fd);
    return 0;
}
