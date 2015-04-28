#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
using namespace std;

class Base{
    public:
        virtual char Value(){
            return 'A';
        }
        virtual char VirtualValue(){
            return 'X';
        }
};

class Derived : public Base{
    public : 
        char Value(){
            return 'U';
        }
};

class VirtualDerived : virtual public Base{
    public:
        char Value(){
            return 'Z';
        }
        char VirtualValue(){
            return 'V';
        }
};

int main(int argc, const char *argv[])
{
    Base *p1 = new Derived();
    Base *p2 = new VirtualDerived();
    
    cout << p1 -> Value() << "_" << p1 -> VirtualValue() << "_" << p2 -> Value() << "_" << p2 -> VirtualValue() << endl;
    
    if(typeid(*p1) == typeid(Derived)){     //Derived
        cout << "Good First" << endl;
    }

    if(typeid(*p2) == typeid(Base)){     //VirtualDerived
        cout << "Good second" << endl;
    }

    return 0;
}
