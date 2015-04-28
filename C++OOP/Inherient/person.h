#ifndef __PERSON_C__
#define __PERSON_C__ 

#include <iostream>
#include <string>

class Person{
    public:
        Person();
        Person(const std::string &, const std::string &);
        Person(const Person &);
        Person &operator = (const Person &);
        ~Person();

        void setName(const std::string &);
        std::string getName() const;

        void setAddress(const std::string &);
        std::string getAddress() const;

        void print() const;
    private:
        std::string name_;
        std::string address_;
};

Person::Person()
    :name_(""),
    address_("")
{}

Person::Person(const std::string &name, const std::string &address)
    :name_(name),
    address_(address)
{}

Person::Person(const Person &p)
    :name_(p.name_),
    address_(p.address_)
{}

Person &Person::operator = (const Person &p)
{
    if(this == &p){
        return *this;
    }else{
        this -> name_ = p.name_;
        this -> address_ = p.address_;
        return *this;
    }
}

~Person::Person()
{}

void Person::setName(const std::string &name)
{
    name_ = name;
}

std::string Person::getName() const
{
    return name_;
}

void Person::setAddress(const std::string &address)
{
    address_ = address;
}

std::string Person::getAddress() const
{
    return address_;
}

void print() const
{
    std::cout << "Name : " << name_ << " Address : " << address_ << std::endl;
}

#endif  /*__PERSON_C__*/
