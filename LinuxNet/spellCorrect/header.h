#ifndef __HEAD_H__
#define __HEAD_H__ 

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <list>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>           //isupper(), tolower()函数

inline void ERR_EXIT(const std::string &m)
{
    do{
        std::cerr << m << std::endl;
        exit(EXIT_FAILURE);
    }while(0);
}
inline char &upToLower(char &c)
{
    if(c >='A' && c <= 'Z')
    {
        c += 32;
    }
}

int editDistance(std::string , std::string , int , int );

#endif  /*__HEAD_H__*/
