#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//求解两个数的最大公因数，我们可以使用欧几里德算法：
//两个整数x > y的最大公因子等同于x mod y 与y的最大公因子。

int highestCommonDivide(int x, int y){
    if(x < y){
        swap(x, y);
    }
    
    if(x % y == 0){
        return y;
    }else{
        return highestCommonDivide(y, x%y);
    }
}

//欧几里德算法的非递归实现
int otherOJLD(int x, int y)
{
    while(x != 0 && y != 0){
        if(x < y){
            swap(x, y);
        }
        if(x % y == 0){
            return y;
        }else{
            int tmp = x;
            x = y;
            y = tmp % x;
        }
    }
}

int leastCommonMilti(int x, int y)
{
    int hcd = highestCommonDivide(x, y);
    int xy = x * y;
    return xy / hcd;
}

int main(int argc, const char *argv[])
{
    int x, y;
    while(1){
        cin >> x >> y;
        while(x == 0 || y == 0){
            cerr << "error input ,please input again : " << endl;
            cin >> x >> y;
        }
        cout << "HCD : " << highestCommonDivide(x, y) << endl;
        cout << "Other : " << otherOJLD(x, y)  << endl;
        cout << "LCM : " << leastCommonMilti(x, y) << endl;
        
    }
    return 0;
}
