#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(int argc, const char *argv[])
{
    char pathBuf[100];
    memset(pathBuf, 0, 100);
    getcwd(pathBuf, 100);
    printf("%s\n", pathBuf);
    return 0;
}
