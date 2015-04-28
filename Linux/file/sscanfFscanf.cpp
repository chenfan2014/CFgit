#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
int main(int argc, const char *argv[])
{
    int a, b, c;
    sscanf("99, 97, 98", "%d, %d, %d", &a, &b, &c);
    printf("%c, %c, %c\n", a, b, c);
    return 0;
}
