#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char *argv[])
{
    int i = 10; 
    int j;
    int &ri = i;
    cout << ri << i << endl;    // ri 是i的一个引用，所以任何时候ri和i的值是相同的&ri则是一个地址

    ri = 20;
    cout << &ri << i << endl;

    j = ri;
    cout << &ri << i << endl;
    return 0;
}
