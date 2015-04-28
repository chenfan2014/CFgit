#include <stdio.h>
#include <string.h>
int main(int argc, const char *argv[])
{
    char c;
    while(c = getc(stdin)){
        putc(c, stdout);
    }
    return 0;
}
