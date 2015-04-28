#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
T add(T & lhs, T & rhs){
    return lhs + rhs;
}

int main(int argc, const char *argv[])
{
    int a = 10;
    int b = 100;
    cout << add(a, b) << endl;

    string s1 = "Beijing ";
    string s2 = "shanghai";
    cout << add(s1, s2) << endl;
    return 0;
}
