#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;
int main(int argc, const char *argv[])
{
    int ival;
    if(cin.good()){
        cout << "cin is good " << endl;
    }
    cin >> ival;
    if(cin.fail()){
        cout << "badinput" << endl;
        cin.clear();        //清除状态
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> ival;
        cout << ival;
    }else if(cin.eof()){
        cout << "finish input" << endl;
    }
    return 0;
}
