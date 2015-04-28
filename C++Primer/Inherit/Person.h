#ifndef __INHERIT_C__
#define __INHERIT_C__ 

#include <iostream>
#include <string>
#include <vector>

class Person{
    public:
        Person()
            :age_(0),
            name_(" ")
        {}

        ~Person()
        {}
        
        Person(int age, const std::string &name)
            :age_(0), name_(name)
        {}

        Person &operator = (const Person &p){
            if(this != &p){
                age_ = p.age_;
                name_ = p.name_;
            }
            return *this;
        }

        void print(std::ostream &os) const{
            os << "Name :" << name_ << "  Age :" << age_ << std::endl;
        }
    protected:
        int age_;
        std::string name_;
};

#endif  /*__INHERIT_C__*/
