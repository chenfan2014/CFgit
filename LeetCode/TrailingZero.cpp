#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* 
 * 思路：这里我们需要计算的是n!后面的0 的个数，这样我们考虑5的个数，
 * 也就是说我们这里需要计算我们式子中有多少个5相乘
 * 需要注意的是我们这里的25的倍数不止1个无，125更是有3个5，所以我们需要
 * 对求的数分解因数。
 * 我们使用n/5所得的数则是有多少数是5的倍数。n/25则是25的倍数，这样就可以求解
 */

int trailZero(int n)
{
    int count = 0;

    int i = 0;
    while(i <= n)
    {
        if(i % 5 == 0)
        {
            int r = i;
            while(r % 5 == 0 && r >= 5) //算法复杂度O(N)
            {
                count ++;
                r /= 5;
            }
        }
        i += 5;
    }

    return count;
}


int trailingZero(int n)
{
    int ret = 0;            //算法复杂度为O(log5 n)
    while(n)
    {
        ret += n/5;
        n /= 5;
    }
    return ret;
}

int main(int argc, const char *argv[])
{
    int num;
    cin >> num;
    cout << trailZero(num) << endl;
    cout << trailingZero(num) << endl;
    return 0;
}
