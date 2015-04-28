#include <iostream>
#include <string>
#include <vector>
using namespace std;
string sum(const string &s1, const string &s2)
{
    return s1 + s2;
}

int sum(int a, int b)
{
    return a + b;
}
int main(int argc, const char *argv[])
{
    string str1 = "beijing";
    string str2 = " shanghai";
    int ival1 = 8;
    int ival2 = 9;
    cout << sum(str1, str2) << endl;
    cout << sum(ival1, ival2) << endl;
    return 0;
}
