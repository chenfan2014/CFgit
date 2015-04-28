#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits>
using namespace std;
int strToInt(const char *str){
    int status = 0;
    long long num = 0;
    if(str != NULL){
        const char *digit = str;
        bool minus = false;
        
        if(*digit == '-'){
            minus = true;
        }
        *digit ++;

        while(*digit != '\0'){
            if(*digit >= '0' && *digit <= '9'){
                num = num * 10 + (*digit - '0');
            }
            if(num > std::numeric_limits<int>::max()){
                num = 0;
                break;
            }
            digit ++;
        }
    }else{
        num = 0;
        return 0;
    }
    return num;
}
int main(int argc, const char *argv[])
{
    char *str;
    printf("Please input a string : ");
    scanf("%s", str);
    printf ("The string you input is %s\n", str) ;
    printf("After change : %d", strToInt(str));
    return 0;
}
