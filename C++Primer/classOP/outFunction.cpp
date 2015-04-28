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
        Person ();
        Person (int id, const string &name, int age);

        int getId() const;
        void setId (int id);

        string getName() const;
        void setName(const string &name);

        void setAge(int age);
        int getAge() const;

        void print(std::ostream &os);
};

Person::Person()
    :id_(0),
    name_(" "),
    age_(0)
{}

Person::Person(int id, const string &name, int age)
    :id_(id),
    name_(name),
    age_(age)
{}

int Person::getId() const{
    return id_;
}

void Person::setId(int id){
    id_ = id;
}

string Person::getName() const{
    return name_;
}

void Person::setName(const string &name){
    name_ = name;
}

int Person::getAge() const{
    return age_;
}

void Person::setAge(int age){
    age_ = age;
}

void Person::print(ostream &os){
    os << "Id : " << id_ << "   Name : " << name_ << "   Age : " << age_ << endl;
}

int main(int argc, const char *argv[])
{
    Person p1;
    p1.setId(1);
    p1.setName("chen");
    p1.setAge(23);
    p1.print(cout);

    Person *p2 = new Person;
    p2 -> setId(2);
    p2 -> setName("fan");
    p2 -> setAge(10);
    p2 -> print(cout);

    Person p3(3, "muzi", 20);
    p3.print(cout);
    return 0;
}
