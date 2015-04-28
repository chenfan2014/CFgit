#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* 
 * 回调函数：就是我们自己去定义一个函数，自己实现这个函数的功能
 * 然后把函数作为参数传入到其他的函数中，由其他的函数在运行期间
 * 调用事先定义的函数，这就叫做回调函数。
 */

int countSum(int a, int b)
{
    cout << a + b << endl;
}

void print()
{
    cout << "TestPrint" << endl;
}

void printString(string s)
{
    cout << s << endl;
}

void callBackCount(int (*callBack)(int , int), int a, int b)
{
    countSum(a, b);
}

void callBackPrint(void (*callback)())      //这里我们传入的是函数的指针。如果函数有参数则传入参数
{
    print();
}

void callBackString(void (*callback)(string s), string s)
{
    printString(s);
}

int main(int argc, const char *argv[])
{
    int a = 10;
    int b = 100;
    callBackCount(countSum, a, b);

    callBackPrint(print);

    string s = "South China Normal University";
    callBackString(printString, s);
    return 0;
}
