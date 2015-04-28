#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *convertToTitle(int number) {
    if(number == 0){
        return "";
    }
    char s[1024] = "";
    int i = 0;
    while(number)
    {
        int n = number % 26;
        if(n == 0){
            s[i] = 'Z';
            number -= 26;
        }else{
            s[i] = (char)(n - 1 + 'A');
            number -= n;
        }
        i ++;
        if(number != 0){
            number /= 26;    
        }
    }   
    i = 0;
    int size = strlen(s) - 1;
    if(size == 0){
        return s;
    }else{
        while(i < (size + 1)/2)
        {   
            char c = s[i];
            s[i] = s[size - i]; 
            s[size - i] = c;
            i ++; 
        }
        return s;
    }
}
int main(int argc, const char *argv[])
{
    int n;
    while(1)
    {
        scanf("%d", &n);
        char *s = convertToTitle(n);
        printf("%s\n", s);
    }
    return 0;
}
