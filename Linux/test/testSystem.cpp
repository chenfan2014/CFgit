#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main(int argc, const char *argv[])
{
    int ret;
    cout << "Pid is : " << getpid() << endl;
    ret = system("ping 202.116.46.205");

    cout << "Ret = " << ret << endl;
    return 0;
}
