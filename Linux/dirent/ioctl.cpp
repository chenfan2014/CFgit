#include <iostream>
#include <string>
#include <vector>
#include <sys/ioctl.h>
using namespace std;
int main(int argc, const char *argv[])
{
    int fd = 0;
    ioctl(fd, 0);
    return 0;
}
