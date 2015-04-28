#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;
int main(int argc, const char *argv[])
{
    char buf[8] = "neokomg";
    char buffer[] = "shanghai";

    char* const p = buf;    //*号出现在const的左边，指针自身是常量。所以对象是可以改变的
    const char *p = buf;    //*号出现在const的右边，被指向的对象是常量。所以对象是不可变得
    char const *p = buf;

    strcpy(buf, "shangha");

    cout << *p << endl;

    return 0;
}
