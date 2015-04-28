#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/utsname.h>
using namespace std;
int main(int argc, const char *argv[])
{
    struct utsname *uns;
    uname(uns);
    cout << uname.release << endl;
    return 0;
}
