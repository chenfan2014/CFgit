#include <iostream>
#include <string>
#include <vector>
#include "add.h"
#include "sub.h"
using namespace std;
int main(int argc, const char *argv[])
{
    int a = 10, b = 20;
    float x = 1.323131, y = 3.3214324;

    cout << "INT ADD (a + b) : " << addInt(a, b) << endl;
    cout << "INT SUB (a - b) : " << subInt(a, b) << endl;

    cout << "FLOAT ADD(x + y) : " << addFloat(x, y) << endl;
    cout << "FLOAT SUB(x - y) : " << subFloat(x, y) << endl;

    return 0;
}
