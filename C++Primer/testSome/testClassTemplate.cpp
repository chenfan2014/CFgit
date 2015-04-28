#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<class Type> class Queue{
    public:
        Queue();
        Type &front();
        const Type &front () const;
        void push(const Type &);
        void pop();
        bool empty() const;
    private:

};

int main(int argc, const char *argv[])
{
    
    return 0;
}
