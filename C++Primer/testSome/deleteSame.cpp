#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;

char *deleteSame(char *str)
{
   int len = strlen(str);
   char arr[len];

   for(int i = 0; i != len - 1; i ++){
        
   }
}

int add_no_arithm(int a, int b)
{
    if(b == 0){
        return a;
    }
    int sum = a ^ b;
    int carry = (a & b) << 1;
    return add_no_arithm(sum, carry);
}

int main(int argc, const char *argv[])
{
    char str[] = "beijing";
    char str1[] = "bei";
    char *s = str;

    cout << sizeof(int) << endl;
    cout << sizeof(double) << endl;
    cout << sizeof(char) << endl;
    cout << sizeof(str) << endl;
    cout << sizeof(s) << endl;

    int a = 8;
    cout << 8 * ++ a << endl;

    cout << deleteSame(str) << endl;
    cout << deleteSame(str1) << endl;
    return 0;
}
