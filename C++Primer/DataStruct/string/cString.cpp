#include <iostream>
#include <string>
#include <vector>
#include <assert.h>

using namespace std;

size_t strlen(const char *str)
{
    assert(str != NULL);        //判断是否是空串
    int len = 0;
    while((*str ++) != '\0'){
        len ++;
    }
    return len;
}

char *strcpy(char *dest, const char *src)
{
    assert(src != NULL && dest != NULL);
    size_t size = strlen(src);
    char *str = new char[size + 1];
    size_t i = 0;

    while(*src != '\0'){
        str[i ++] = *src ++;
    }
    return str;
}

char *strcat(char *dest, const char *src)
{
    assert(dest != NULL && src != NULL);
    size_t size = strlen(src) + strlen(dest);
    size_t len = strlen(dest);
    char *str = dest;
    
    cout << str[len - 1] << endl;

    while(*src != '\0'){
        cout << *src ++ << " ";
        
    }
    return str;
}

int main(int argc, const char *argv[])
{
    char *str1 = "Beijing";
    char *str2 = "shanghai";
    cout << strcpy(str1, str2) << endl;
    cout << strcat(str1, str2) << endl;
    return 0;
}
