#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <assert.h>
using namespace std;

void deleteSpace(char *str)
{
    assert(str != NULL);
    int len = strlen(str);
    while(*str == ' ')
    {
        for(int i = 1; i != strlen(str) - 1; i ++)
        {
            str[i - 1] = str[i];
        }
        len --;
    }
    while(str[len] == ' '){
        len --;
    }
   
    str[len + 1] = '\0';
    for(int i = 0; i != strlen(str); i ++)
    {
        if(str[i] == ' ' && str[i + 1] == ' ')
        {
            for(int j = i; j != strlen(str) - 1; j ++)
            {
                str[j] = str[j + 1];
            }
            i --;
            len --;
        }
    }

    str[len + 1] = '\0';
    cout << str << " " << strlen(str) << endl;
}

int main(int argc, const char *argv[])
{
    char str[] = "    beijing shi    shanghai  tshifad  fda fda      ";
    
    cout << "Before delete : " << str << "   strlen = " << strlen(str) << endl;
    
    deleteSpace(str);
    
    cout << "After delete : " << str << endl;

    return 0;
}
