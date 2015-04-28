#include <iostream>
#include <string>
#include <vector>
using namespace std;

int add(int x, int y)
{
    if(y == 0){
        return x;
    }
    int sum, ret;
    sum = x ^ y;
    ret = (x & y) << 1;
    return add(sum, ret);
}

int avg(int x, int y)
{
    int avg = add(x, y) >> 1;
    return avg;
}

int main(int argc, const char *argv[])
{
    int a, b, sum;
    while(1){
        cin >> a >> b;
        cout << add(a, b) << endl;
        cout << "Avg : " << avg(a, b) << endl;
    }
    
    
    return 0;
}
