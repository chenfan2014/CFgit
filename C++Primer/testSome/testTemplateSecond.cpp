#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<typename T>
T sum(const T &a, int b){
    return a + b;
}

int main(int argc, const char *argv[])
{
    const int b = 1;
    char str = 'a';
    cout << sum(str, b) << endl;
    return 0;
}
