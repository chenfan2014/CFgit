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
        Person ()
            :id_(0),
             name_(" "),
             age_(0)
        {}
        /*
        Person (int id, const string &name, int age)
            :id_(id),
             name_(name),
             age_(age)
        {}*/
        Person (int id, const string &name, int age){
            id_ = id;
            name_ = name;
            age_ = age;
        } 
        int getId() const{
            return id_;
        }
        void setId (int id){
            id_ = id;
        }

        string getName() const{
            return name_;
        }
        void setName(const string &name){
            name_ = name;
        }
        void setAge(int age){
            age_ = age;
        }
        int getAge() const{
            return age_;
        }
        void print(std::ostream &os){
            os << "id : " << id_ << endl << "name : " << name_ << endl << "age : " << age_<< endl;
        }
};

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
