#ifndef __STUDENT_C__
#define __STUDENT_C__ 

#include "Person.h"

class Student : public Person{
    private:
        int stuId_;
    public:
        Student()
            :stuId_(0)
        {}

        Student(int age, const std::string &name, int stuId)
            :Person(age, name), stuId_(stuId)
        {}
        
        Student(const Student &s)
            :Person(s),stuId_(s.stuId_)
        {}

        Student &operator = (const Student &s){
            if(this != &s){
                Person::operator = (s);
                stuId_ = s.stuId_;
            }
            return *this;
        }

        void print(std::ostream &os) const{
            os << "Name :" << name_ << "  Age :" << age_ << " StuID :" << stuId_ << std::endl;
        }

};

#endif  /*__STUDENT_C__*/
