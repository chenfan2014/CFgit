#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Base{
    public:
        Base()
            :str_("")
        {
            count_ ++;
        }
        ~Base()
        {
            count_ --;
        }
        static int getStaticData() {
            return count_;
        }
    private:
        static int count_;
        string str_;

};

int Base::count_ = 0;

int main(int argc, const char *argv[])
{
    Base b1;
    cout << Base::getStaticData() << endl;
    
    Base b2;
    cout << b2.getStaticData() << endl;

    return 0;
}
