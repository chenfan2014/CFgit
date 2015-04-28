#include <iostream>
#include <string.h>
#include <vector>
#include <stdlib.h>     //malloc是库函数，new是操作符
using namespace std;
void GetMemory(char *p)
{
    p = (char *)malloc(11);
}
int main(int argc, const char *argv[])
{
    char str[] = "Hello";
    GetMemory(str);
    
    cout << strlen(str) << endl;
    strcpy(str, "South na U");
    cout << str << endl;
    return 0;
}
