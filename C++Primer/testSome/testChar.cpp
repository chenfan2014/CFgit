#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int main(int argc, const char *argv[])
{
    char p[] = "Beijing";
    p[1] = 'h';
    cout << p << endl;

    char *ptr = "Shanghai";
    //ptr[2] = 'i';
    cout << ptr << endl;
    return 0;
}
