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

/* 
 * 这里我们有一个O(N)的方法可以解决
 * 我们先遍历一遍，把所有的空格找出来，这样我们就可以判断出来一共要多少空间
 * 之后我们从后面往前进行查找，当我们找的不是空格的时候，我们移动我们的元素
 * 当是空格的时候则插入
 */

string spaceToStr(const string &s)
{
    int total = s.size();
    for(size_t i = 0; i != s.size(); i ++){
        if(s[i] == ' '){
            total += 3;
        }
    }
    
    string str(s);
    return str;
}

int main(int argc, const char *argv[])
{
    string str = "How are you";
    str = spaceToString(str);
    cout << str << endl;
    return 0;
}
