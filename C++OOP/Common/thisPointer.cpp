#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Do{
    private:
        string str_;
        int num_;
    public:
        Do();
        Do(const string &, int );
        ~Do();
        Do(const Do &);
        Do operator = (const Do &);
        void print() const;
};

Do::Do()
    :str_(" "),
    num_(0)
{}

Do::Do(const string &str, int num)
    :str_(str),
    num_(num)
{}

Do::~Do()
{}

Do::Do(const Do &d)
    :str_(d.str_),
    num_(d.num_)
{}

Do Do::operator = (const Do &d){
    if(&d != this){
        str_ = d.str_;
        num_ = d.num_;
    }
    return *this;
}

void Do::print() const{
    cout << "String : " << this -> str_ << "  Num : " << num_ << endl;
}

int main(int argc, const char *argv[])
{
    Do d1("Beijing", 12);
    Do d2;
    d2.print();
    d2 = d1;
    d2.print();
    return 0;
}
