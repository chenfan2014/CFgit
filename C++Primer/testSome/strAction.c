#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strlenSelf(const char *src)
{
    int count = 0;
    while(*src ++){
       count ++;
    }
    return count;
}

char *strcpySelf(char *dst, const char *src)
{
    int i;
    int len = strlenSelf(src);
    dst = (char *)malloc(sizeof(char) * len);
    for(i = 0; i != len; i ++){
        dst[i] = src[i];
    }
    return dst;
}

int main(int argc, const char *argv[])
{
    char *str = "Beijing";
    char *s = "shanghai";
    int len = strlenSelf(str);
    printf("%s\n", strcpySelf(s, str));
    printf("%d\n The is %s\n", len, s);
    return 0;
}
