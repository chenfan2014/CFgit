#include <iostream>
#include <string>
#include <vector>


using namespace std;

void reserveString(string &str)
{
    int size = str.size();
    for(int i = 0; i != size/2; i ++)
    {
        str[i] = str[i] ^ str[size - i - 1];
        str[size - i - 1] = str[i] ^ str[size - i - 1];
        str[i] = str[i] ^ str[size - i - 1];
    }
}

//我们先把整个字符串反转，然后再进行单词的分割，每一个单词进行反转
void reserve(string &str)
{
    reserveString(str);
    string retStr, midStr;
    int size = str.size();
    
    int beg, end;
    int i = 0;
    beg = 0;
    retStr = "";
    while(str[i] != '\0'){
        if(str[i] == ' '){
            end = i;
            midStr = str.substr(beg, end - beg);
            cout << midStr << endl;
            reserveString(midStr);
            retStr += midStr + " ";
            beg = end + 1;
        }
        i ++;
    }
    
    midStr = str.substr(beg, size - beg);
    reserveString(midStr);
    retStr += midStr;
    
    str = retStr;
}

int main(int argc, const char *argv[])
{
    string str = "Beijing is the capacity of China";
    cout << str << endl;
    reserve(str);
    cout << str << endl;
    return 0;
}
