#include <iostream>
#include <string>
#include <vector>
#include "string.h"
using namespace std;
using namespace str_;
int main(int argc, const char *argv[])
{
    String str("china");
    str.print();
    cout << str.size() << endl;
    String s(str);
    s.print();
    cout << "success" << endl;
    return 0;
}
