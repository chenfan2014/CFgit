#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Object{
    private:
        int a;
    public:
        Object()
        {}
        Object(int i)
            :a(i)
        {}
};

int main(int argc, const char *argv[])
{
    Object *obj = new Object[100]();
    return 0;
}
