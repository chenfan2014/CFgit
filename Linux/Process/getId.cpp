#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
using namespace std;
int main(int argc, const char *argv[])
{
    cout << getpid() << endl;
    cout << getppid() << endl;
    cout << getuid() << endl;
    cout << geteuid() << endl;
    cout << getgid() << endl;
    cout << getegid() << endl;
    return 0;
}
