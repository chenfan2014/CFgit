#include <iostream>
#include <string>
#include <vector>
#include <exception>
using namespace std;

void func()
{
    int num;
    cin >> num;
    if(num < 0){
        throw("input error");
    }
}

int main(int argc, const char *argv[])
{
    try{
       func();
    }catch(...){
        cout << "Get it" << endl;
    }
    return 0;
}
