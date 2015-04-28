#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Base{
    private:
        static int i;
        const int c;
    public:
        static const int b = 100;
        Base()
            :c(100)
        {}
};

int Base::i = 1231321;

const int Base::b;

int main(int argc, const char *argv[])
{
    cout << Base::b << endl;   
    return 0;
}
