#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Base{
    public:
        static int c;
};
class Derived{
    public:
        static int c;
};

int Base::c = 1;
int Derived::c = 2;

int main(int argc, const char *argv[])
{
    cout << Base::c << endl;
    cout << Derived::c << endl;


    return 0;
}
