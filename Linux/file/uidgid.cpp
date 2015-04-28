#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
using namespace std;
int main(int argc, const char *argv[])
{
    cout << "getuid : " << getuid() << endl;
    cout << "getpid : " << getpid() << endl;
    cout << "getppid : " << getppid() << endl;
    cout << "getgid : " << getgid() << endl;
    return 0;
}
