#include <iostream>
#include <string>
#include <vector>
#include <stddef.h>
#include <string.h>
#include <assert.h>
#include <exception>
using namespace std;

template<class AType>
class SafeResource{
    public:
        SafeResource(size_t size = 1)
        {
            if(size > 0){
                rp_ = new AType[size];
            }else{
                rp_ = 0;
            }
        }

        ~SafeResource()
        {
            delete rp_;
        }

        operator AType *(){
            return rp_;
        }
    private:
        AType *rp_;
};

int main(int argc, const char *argv[])
{
    SafeResource<char> sa(100);
    strcpy(sa, "This is a template");
    int i = 0;
    try{
        cout << sa << endl;
        assert(i == 0);
        throw("Wrong");
    }catch(const char *cstr){
        cout << "catch the message" << endl;
    }
    return 0;
}
