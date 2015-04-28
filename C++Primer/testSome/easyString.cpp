#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;
int stringMatch(const char *str, const char *patten)
{
    int pos, i, j;
    int strLen = strlen(str);
    int pattenLen = strlen(patten);
    
    for(i = 0; i != strLen - pattenLen; i ++)
    {
        int index = 0;
        int count = 0;
        for(j = i; j != i + pattenLen; j ++)
        {
            if(str[j] == patten[index ++])
            {
                count ++;
            }
        }
        if(count == pattenLen)
        {
            pos = i;
            return pos;
        }
    }
    return 0;
}
int main(int argc, const char *argv[])
{
    char *str1 = "abcdabcabcccaddacbd";
    char *str2 = "abcc";
    
    int pos = stringMatch(str1, str2);
    cout << pos << endl;
    return 0;
}
