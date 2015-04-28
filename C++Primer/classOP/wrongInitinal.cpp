#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Num{
    private:
        int num_;
        int ival_;
    public:
        Num(int ival)
            :ival_(ival),
            num_(ival_)
        {}

        void print(ostream &os){
            os << "ival = " << ival_ << " num = " << num_ << endl;
        }

};
int main(int argc, const char *argv[])
{
    Num n(9);
    n.print(cout);
    return 0;
}
