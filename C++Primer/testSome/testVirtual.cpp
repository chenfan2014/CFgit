#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
using namespace std;

class A{
    public:
        A(){
            cout << "A con" << endl;
        }
        virtual void fun(int number = 10){
            cout << "A::fun number is " << number << endl;
        }
};

class B : public A{
    public :
        B(){
            cout << "B con" << endl;
        }
        virtual void fun(int number = 2){
            cout << "B::fun number is " << number << endl;
        }
};

int main(int argc, const char *argv[])
{
    B b;
    A *a = &b; 

    //虚函数动态绑定到B，但是缺省实参编译的时候确定的是10，而不是20
    a -> fun();
    if(typeid(*a) == typeid(B)){
        cout << "Good" << endl;
    }
    return 0;
}
