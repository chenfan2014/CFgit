#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int titleNumber(string s)
{
    int num = 0;
    for(int i = s.size() - 1; i >= 0; -- i)
    {
        int number = pow(26, s.size() - 1 - i) * (int)(s[i] - 'A' + 1);
        num += number;
        
    }
    return num;
}

int main(int argc, const char *argv[])
{
    string s;
    while(1){
        cin >> s; 
        cout << titleNumber(s) << endl;
    }
    return 0;
}
