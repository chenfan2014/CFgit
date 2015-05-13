#include <iostream>
#include <string>
#include <vector>

// 这个是实现我们的阶乘

//递归函数的三个要点：
//第一：我们要调用自身
//第二：我们必须要有结束的条件
//第三：我们的小问题必须可以求得结果
int factorial(int n)
{
    if(n == 0 && n == 1){
        return n;
    }
    while(n > 1){
        return n * factorial(n - 1);
    }
}

int factorialTwo(int n)
{
    if(n == 0 && n == 1){
        return n;
    }
    int ret = 1;
    for(int i = 1; i != n + 1; i ++)
    {
        ret *= i;
    }
    return ret;
}

using namespace std;

/*
int main(int argc, const char *argv[])
{
    cout << factorial(10) << endl;
    cout << factorial(4) << endl;

    cout << factorialTwo(4) << endl;
    return 0;
}
*/
