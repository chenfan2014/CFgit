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
    Person p;
    p.getAge();
    p.setAge(12);
    return 0;
}
