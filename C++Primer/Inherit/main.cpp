#include <iostream>
#include <string>
#include <vector>
#include "Person.h"
#include "Student.h"
using namespace std;
int main(int argc, const char *argv[])
{
    Student s1(23, "chenfan", 1);
    Student s2(s1);
    s1.print(cout);
    s1.Person::print(cout);
    cout << "--------------------------------" << endl;
    s2.print(cout);
    s2.Person::print(cout);
    return 0;
}
