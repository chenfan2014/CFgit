#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <assert.h>

using namespace std;

#define MAXSIZE 1024
int strintToNumber(char *str)
{
    assert(str != NULL);
    int num = 0;
    char *s = str;
    char c = *s;
    
    if(c == '-' || c == '+'){
        s ++;
    }

    
    while(*s != '\0')
    {
        if(*s >= '0' && *s <= '9'){
            num = num * 10 + (*s - '0');
        }
        s ++;
    }
    if(c == '-'){
        num = 0 - num;
        return num;
    }
    return num;

}

int main(int argc, const char *argv[])
{
    char *str;
    scanf("%s", str);
    cout << strintToNumber(str) << endl;
    return 0;
}
