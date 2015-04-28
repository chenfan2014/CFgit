#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, const char *argv[])
{
    string s = "beijing";
    string sfind;
    while(cin >> sfind){
        string::size_type ix = s.find(sfind.c_str());
        if(ix != string::npos){
            cout << sfind << endl;
        }else{
            cout << "not found" << endl;
        }
    }
    return 0;
}
