#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Test{
    private:
        int val_;
    public:
        //void operator = (const T &);
        Test operator + (const Test &t1, const Test &t2) const{
            return t1.val_ + t2.val_;
        }

};

int main(int argc, const char *argv[])
{
    Test t1(100);
    Test t2(200);
    Test t3;
    t3 = t1 + t2;
    cout << t3 << endl;
    
    return 0;
}
