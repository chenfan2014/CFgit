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

        ~Student()
        {}

        Student(int id, const string &name, int age)
            :id_(id),
            name_(name),
            age_(age)
        {}

        

        Student(const Student &stu){
            id_ = stu.id_;
            name_ = stu.name_;
            age_ = stu.age_;
        }
        
        Student &operator = (const Student &stu){
            cout << "use self = operator " << endl;
            id_ = stu.id_ + 1;
            name_ = stu.name_;
            age_ = stu.age_ + 2;
            return *this;
        }

        void print(ostream &os){
            os << "ID : " << id_ << "   Name : " << name_ << "    Age : " << age_ << endl; 
        }
};

int main(int argc, const char *argv[])
{
    Student s1(1, "chenfan", 23);
    Student s2;
    s2 = s1;
    s1.print(cout);
    cout << "---------------------------------------------" << endl;
    s2.print(cout);

    return 0;
}
