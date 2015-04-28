#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char *argv[])
{
    string s1, s2;
    while(1)
    {
        cin >> s1 >> s2;
        if(s1 > s2){
            cout << s1 + s2 << " " << s2 + s1 << endl;
        }else{
            cout << s2 + s1 << " " << s1 + s2 << endl;
        }
    }
    return 0;
}
