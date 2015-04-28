#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;
int a = 10;

char *getStr()
{
    char *p = (char *)malloc(8);
    if(p == NULL){
        return NULL;
    }else{
        p = "Beijig";
    }

    return p;
}
int main(int argc, const char *argv[])
{
    cout << a << endl;
    int a = 100;
    cout << a << endl;
    char *str = getStr();
    cout << str << endl;
    return 0;
}
