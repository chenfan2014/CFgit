#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string fractionToDecimal(int m, int n)
{
    ostringstream s;
    long double res = ( long double)m / (long double)n;
    s << res;
    string str = s.str();

    string s1, s2;
    for(string::size_type ix = 0; ix != str.size(); ++ix)
    {
        if(str[ix] == '.'){
            s1 = str.substr(0, ix + 1);
            s2 = str.substr(ix + 1);
        }
    }
    if(s2[0] == s2[1])
    {
        s2[0] = '(';
        s2[2] = ')';
        s2 = s2.substr(0, 3);
    }
    str = s1 + s2;
    cout << str << endl;
    return str;
}

int main(int argc, const char *argv[])
{
    int m, n;
    while(1)
    {
        cin >> m >> n;
        cout << fractionToDecimal(m, n) << endl;
    }
    return 0;
}
