#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char *argv[])
{
    int ival = 100;
    int ival2 = 200;
    int *p = &ival;     //这个时候是一个指针的引用
    p = &ival2;         //修改的是指针自身的值
    cout << *p << endl;
    
    *p = ival;          //修改的是指针对象的值
    cout << ival2 << endl;

    return 0;
}
