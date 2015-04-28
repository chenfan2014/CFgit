#include <iostream>
#include <string>
#include <vector>
#include <string.h>

char *strcatS(char *strDest, const char *strSrc)
{
    char *newStr = strDest;
    assert((strDest != NULL) && (strSrc != NULL) ); //判断这两个是非空字符串
    while(*strDest){
        strDest ++;
    }
    while(*strDest ++ = *strSrc ++);
    return  newStr;
}

char *strcpyS(char *strDest, const char *strSrc)
{
    char *newStr = strDest;
    
    assert((strDest != NULL) && (strSrc != NULL)); 
    while((*strDest ++ = *strSrc ++) != 0);
    return newStr;
}
