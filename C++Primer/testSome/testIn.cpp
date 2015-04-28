#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Base{
    int a;
};

class DerivedOne : virtual public Base{
    int b;  
};

class DerivedTwo : virtual public Base{
    int c;  
};

class Derived : public DerivedOne, public DerivedTwo{
    int d;
};

int main(int argc, const char *argv[])
{
    cout << sizeof(Base) << endl;
    cout << sizeof(DerivedOne) << endl;
    cout << sizeof(Derived) << endl;
    return 0;
}
