#include <iostream>
#include <string>
#include <vector>
using namespace std;
int const &max(int const &a, int const &b)
{
    return a > b ? a : b;
}

int &fun(int &a)
{
    cout << a << endl;
    a += 5;
    cout << a << endl;
    return a;
}

int *fun2(int *a)
{
    return a;
}

int main(int argc, const char *argv[])
{
    int ii = 10; 
    int j = 20;

    fun(ii) = 800;      //我们把800赋值给一个函数
    cout << ii << endl;

    funDo(ii) = 800;

    return 0;
}
