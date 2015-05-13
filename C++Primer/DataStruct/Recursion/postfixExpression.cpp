#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main(int argc, const char *argv[])
{
    stack<char> sNum;
    stack<char> sOp;
    
    string str;
    cin >> str;
    for(int i = 0; i != str.size(); i ++){
        sNum.push(str[i]);
    }
    while(!sNum.empty()){
        cout << sNum.top() << " ";
        sNum.pop();
    }
    cout << endl;

    return 0;
}
