#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char  *strcpySelf(char *dst, const char *src)
{
    assert(src != NULL);
    
    char *address = dst;
    while((*dst ++ = *src ++) != '\0');
    printf("%s\n", dst);
    return dst;
}
int main(int argc, const char *argv[])
{
    char *src = "Beijing";
    char *dst;
    strcpySelf(dst, src);
    printf("%s", dst);
    return 0;
}
