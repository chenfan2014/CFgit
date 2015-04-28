#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
using namespace std;
int main(int argc, const char *argv[])
{
    cout << typeid(int).name() << endl;
    return 0;
}
