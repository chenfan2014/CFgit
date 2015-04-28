#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

#pragma pack(4)
struct T_Test{
    char cTest;
    int iTest;
    short int sTest;
};

void fun(char a[3])
{
    cout << sizeof(a) << endl;      //结果为4，这里的数组蜕变成了指针，所以sizeof(a)就是求指针的sizeof
}

int main(int argc, const char *argv[])
{
    int i = 100;
    unsigned int ui = 100;
    double d = 100.0;
    char b = 'a';
    string str = "China";
    char *p;

    //cout << sizeof int << endl; //这句是错误的，sizeof(int)这里必须加括号,如果是类类型，也需要加括号  
    
    printf("%d\n", sizeof T_Test);
    //cout << sizeof T_Test << endl;

    char a[3];
    fun(a);
    cout << sizeof(p) << endl;

    cout << "unsigned int " << sizeof(ui) << endl;
    cout << "sizeof double : " <<  sizeof(d) << endl;
    cout << "Sizeof i " << sizeof(i) << endl;
    cout << "Sizeof b " << sizeof(b) << endl;
    cout << "Sizeof str " << sizeof(str) << endl;

    cout << 1 + 11.11  << endl;


    return 0;
}
