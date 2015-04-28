#include <iostream>
#include <string>
#include <vector>
using namespace std;

class X{
    public:
        friend class Y;
        friend void print(const X &x, std::ostream &os);

        X()
            :ival_(100),
            str_("None")
        {}


    private:
        int ival_;
        string str_;
};

class Y{
    public:
        void print(const X &x){
            cout << x.ival_ << " " << x.str_ << endl;
        }
};

void print(const X &x, std::ostream &os){
    os << " print function " << endl << "ival = " << x.ival_ << "   str = " << x.str_ << endl;
}

int main(int argc, const char *argv[])
{
    X x;
    Y y;
    y.print(x);
    print(x, cout);
    return 0;
}
