#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
#include <string.h>
using namespace std;


void multiply(const char *a, const char *b)
{
    assert(a != NULL && b != NULL);

    int i, j, lenA, lenB, *s;
    lenA = strlen(a);
    lenB = strlen(b);

    s = (int *)malloc(sizeof(int) * (lenA + lenB));     //存储计算结果

    for(i = 0; i != lenA; i ++)
    {
        for(j = 0; j != lenB; j ++)
        {
            s[i + j + 1] += (a[i] - '0')*(b[j] - '0');
        }
    }

    //下面实现进位
    for(i = lenA + lenB -1; i >= 0; --i)
    {
        if(s[i] >= 10)
        {
            s[i - 1] += s[i] / 10;
            s[i] = s[i] % 10;
        }
    }

    char *c = (char *)malloc(sizeof(char) * (lenA + lenB));
    i = 0;
    while(s[i] == 0){
        i ++;               //跳过头部0元素
    }

    for(j = 0; )


}

int main(int argc, const char *argv[])
{
    
    return 0;
}
