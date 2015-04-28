#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <stdio.h>
using namespace std;

int main(int argc, const char *argv[])
{
    unsigned int a = 0x1FFFFFF7;

    unsigned char b = a;
    char c = a;
    unsigned char *p = (unsigned char *)&a;
    printf("%x\n", b);
    printf("%x\n", c);
    printf("%x\n", *p);
    printf("%x, %x, %x\n", b, c, *p);
    return 0;
}
