#include <iostream>
#include <string>
#include <vector>
using namespace std;

void swap(int &a, int &b)
{
    a = a ^ b;
    cout << a << " : " << b << endl; 
    b = a ^ b;
    cout << a << " : " << b << endl; 
    a = a ^ b;
    cout << a << " : " << b << endl; 
}

int main(int argc, const char *argv[])
{
    int a = 100;
    int b = 99;
    swap(a, b);
    cout << a << " " << b << endl;
    return 0;
}
