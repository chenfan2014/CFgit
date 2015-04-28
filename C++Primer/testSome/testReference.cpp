#include <iostream>
#include <string>
#include <vector>
using namespace std;

string::size_type findChar(const string &s, char c){
    string::size_type i = 0;
    while(i != s.size() && s[i] != c){
        ++i;
    }
    return i;
}

int main(int argc, const char *argv[])
{
    string str("China");
    cout << findChar(str, 'a') << endl;
    cout << findChar("China", 'a') << endl;
    return 0;
}
