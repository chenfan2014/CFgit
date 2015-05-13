#include <iostream>
#include <string>
#include <vector>

using namespace std;

//我们有1×2的瓷砖，我们需要用来铺再2×M的地面上，问有多少种方式
//假设我们铺设公式为fun();
//而我们瓷砖铺设有横和竖两种方式
//第一：当我们横着放：我们此时还有fun(M - 2)种方式
//第二：当我们竖着房，我们此时还有fun(M - 1)种方式
//所以fun(M) = fun(M - 1) + fun(M - 2);

int fun(int size)
{
    if(size == 1 || size == 2){
        return size;
    }else{
        return fun(size - 1) + fun(size - 2);
    }
}

int main(int argc, const char *argv[])
{
     
    return 0;
}
