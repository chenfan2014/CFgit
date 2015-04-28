#include <iostream>
#include <string>
#include <vector>
using namespace std;

class A{
    public:
        A(){cout << "A" << endl;}
        ~A(){cout << "~A" << endl;}
    private:
};

class B : public A{
    public:
      B(A &a)
          :oa(a)
      {cout << "B" << endl;}

      ~B()
      {
        cout << "~B" << endl;
      }
    private :
      A oa;
};

int main(int argc, const char *argv[])
{
    A a;
    B b(a);
    return 0;
}
