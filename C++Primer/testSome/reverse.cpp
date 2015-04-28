#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;
#define MAXSIZE 1024
char *reverseWord(char *s)
{
    char c;
    int len = strlen(s);

    for(int i = 0; i != len / 2; i ++){
        c = *(s + i);
        *(s + i) = *(s + len - (i + 1));
        *(s + len - (i + 1)) = c;
    }
    return s;
}

char *reverseSentence(char *s)
{
    char *mid;
    int count = 0;
    char *str = "";
    char *s2 = s;
    s = reverseWord(s);
    
    for(int i = 0; i != strlen(s) - 1; i ++){
        cout << "i =  " << i  << endl;
        if(*(s + i) == ' '){
            count = i - count;
            cout << s2 << endl;
            cout << str << endl;
            strcpy(str, )
            count ++;
        }
    }

    return s;
}

int main(int argc, const char *argv[])
{
    char str[] = "Beijing is a big city"; 

    cout <<  reverseSentence(str) << endl;
    return 0;
}
