#include <iostream>
#include <string>
#include <vector>
#include <stdarg.h>

using namespace std;

int max(int num, ...)
{
    va_list ap;
    int maxNum = -65535;
    int midNum;
    
    //va_start()表示我们可以取得可变参数的首指针
    va_start(ap, num);
    for(int i = 0; i != num; i ++)
    {
        midNum = va_arg(ap, int);   //依次取得我们的多个参数
        if(maxNum < midNum){
            maxNum = midNum;
        }
    }
    va_end(ap);             //结束多参数的计算

    return maxNum;
}

int add(int num, ...)
{
    int sum = 0;
    int index = 0;
    va_list ap;
    va_start(ap, num);
    
    for(; index != num; ++index)
    {
        int mid = va_arg(ap, int);
        sum += mid;
    }

    va_end(ap);
    return sum;
}

int main(int argc, const char *argv[])
{
    int i = 1, j = 9, k = 3;
    cout << add(3, i, j, k) << endl;
    cout << max(3, i, j, k) << endl;
    return 0;
}
