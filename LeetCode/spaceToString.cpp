#include <iostream>
using namespace std;
string spaceToString(string s)
{
    string newStr;
    for(int i = 0; i != s.size(); i ++){
        if(s[i] == ' '){
            s.erase(i, 1);
            s.insert(i, "%20");
            i += 2;
        }
    }
    return s;
}
int main(int argc, const char *argv[])
{
    string str = "How are you";
    str = spaceToString(str);
    cout << str << endl;
    return 0;
}
