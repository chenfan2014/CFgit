#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <stdio.h>
using namespace std;

int strToNum(const char *str)
{
    int num = 0;
    int len = strlen(str);
    for(int i = 0; i != len; i ++)
    {
        int ret = str[i] - 48;
        if(str[i] >= '0' && str[i] <= '9'){
            num = num * 10 + ret;
        }
    }
    return num;
}

int main(int argc, const char *argv[])
{
    string str;
    cin >> str;
    int num = strToNum(str.c_str());
    cout << num << endl;
    return 0;
}
