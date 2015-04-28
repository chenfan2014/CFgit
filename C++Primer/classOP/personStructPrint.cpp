#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Person{
    int id_;
    string name_;
    int age_;

    void print(std::ostream &os){
        os << "id : " << id_ << " name : " << name_ << " age : " << age_ << endl;
    }
};
int main(int argc, const char *argv[])
{
    Person p1;
    p1.id_ = 100;
    p1.name_ = "chenfan";
    p1.age_ = 23;
    p1.print(cout);

    Person *p2 = new Person;
    p2 -> id_ = 101;
    p2 -> name_ = "muzi";
    p2 -> age_ = 21;
    p2 -> print(cout);
    return 0;
}
