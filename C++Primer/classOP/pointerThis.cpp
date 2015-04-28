#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Person{
    private:
        int id_;
        string name_;
        int age_;
    public:
        Person()
            :id_(0),
            name_(" "),
            age_(0)
        {}

        Person(int id, const string &name, int age)
            :id_(id),
            name_(name),
            age_(age)
        {}

        Person &setId(int id){
            id_ = id;
            return *this;
        }

        Person &setName(const string &name){
            name_ = name;
            return *this;
        }

        Person &setAge(int age){
            age_ = age;
            return *this;
        }

        Person &print(std::ostream &os){
            os << "ID : " << id_ << "   Name : " << name_ << "    Age : " << age_ << endl;
            return *this;
        }
        const Person &print(std::ostream &os) const{
            os << "ID : " << id_ << "   Name : " << name_ << "    Age : " << age_ << endl;
            return *this;
        }
};
int main(int argc, const char *argv[])
{
    Person p;
    p.print(cout);
    cout << "------------------------------" << endl;
    
    p.setId(12).print(cout).setAge(22).print(cout).setName("henfan").print(cout);
    return 0;
}
