#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int f(int val){
    int num = 0;
    int *ptr = &num;
    printf("%p\n", ptr);
    if(val == 0){
        int ival;
        ival = 5;
        ptr = &ival;
    }
    printf("%p\n", ptr);
    return (*ptr + 1);
}
int main(int argc, const char *argv[])
{
    int iret = 0;
    int ival = 0;
    iret = f(ival);
    printf("iret = %d\n ", iret);
    return 0;
}
