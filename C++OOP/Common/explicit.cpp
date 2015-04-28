#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Do{
    private:
        string str_;
    public:
        Do();
        //Do(const string &);
        ~Do();
        Do(const Do &);
        Do operator = (const Do &);
        void print() const;
};

Do::Do()
    :str_(" ")
{}
/*
Do::Do(const string &str)
    :str_(str)
{}
*/
Do::~Do()
{}

Do::Do(const Do &d)
    :str_(d.str_)
{}

Do Do::operator = (const Do &d){
    if(&d != this){
        str_ = d.str_;
    }
    return *this;
}

void Do::print() const{
    cout << "String : " << str_ << endl;
}

int main(int argc, const char *argv[])
{
    Do d1("beijing");
    Do d2;
    d2.print();
    d2 = d1;
    d2.print();
    return 0;
}
