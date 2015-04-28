#include <iostream>
#include <string>
#include <vector>
using namespace std;    
class Student{
    private:
        int id_;
        string name_;
        int age_;
    public:
        Student()
            :id_(0),
            name_(" "),
            age_(0)
        {}
        Student(int id, const string &name, int age)
            :id_(id),
            name_(name),
            age_(age)
        {}
        void print(){
            cout << id_ << "  " << name_ << "  " << age_ << endl;
        }

        Student &operator = (const Student &stu){
            id_ = stu.id_;
            name_ = stu.name_;
            age_ = stu.age_;
            return *this;
        }
};
int main(int argc, const char *argv[])
{
    Student s(12, "chen", 21);
    Student s1 = s;
    s.print();
    s1.print();
    return 0;
}
