#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Test{
    private : 
        int val;
    public:
        explicit Test(int v)
            :val(v)
        {}
        
            
        
};

int main(int argc, const char *argv[])
{
    Test t1(10);
    Test t = 1;
    return 0;
}
