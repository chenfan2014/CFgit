#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, const char *argv[])
{
    char *str;
    char *str2;
    char *str3;
    printf("%s\n", str);
    str = (char *)malloc(20 * sizeof(char));
    /*malloc 函数是void *类型，这里我们需要是对char *类型进行内存分配
     * 本来void*可以通过char *直接转换，但是这里可能编译器会报错
     * 这里我们在malloc前面使用(char *),这里我们使用这个是进行强制转化
     */
    printf("%s\n", str);
    
    str2 = (char *)realloc(NULL, 20 * sizeof(char));
    return 0;
}
