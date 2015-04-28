#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;

const int SIZE = 1024;
string numberToTitle(int number)
{
    if(number == 0){
        return "";
    }
    char s[SIZE] = "";
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
        number /= 26;
    }
    
    i = 0;
    int size = strlen(s) - 1;
    while(i < (size + 1)/2)
    {
        char c = s[i];
        s[i] = s[size - i];
        s[size - i] = c;
        i ++;
    }
   
    return s;
}



int main(int argc, const char *argv[])
{
    //706 AAD   1457 BDA  
    int n;
    while(1)
    {
        cin >> n;
        cout << numberToTitle(n) << endl;
    }
    return 0;
}
