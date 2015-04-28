#include <iostream>
#include <string>
#include <vector>
using namespace std;

void prim(int m, int n)
{
    if(m > n){
        while(m % n != 0){      //无法整除
            n ++;
        }
        m = m / n;
        prim(m, n);
        cout << n << endl;
    }
}

int main(int argc, const char *argv[])
{
    int n = 1024;
    prim(435234, 2);
    return 0;
}
