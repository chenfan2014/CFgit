#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
#include <stdexcept>

using namespace std;

template<typename T>
T sumNum(T t1, T t2){
    if(t1 < 0){
        throw t1;
    }
    return t1 + t2;
}

int main(int argc, const char *argv[])
{
    int i, j;
    while(cin >> i >> j){
        try{
            cout << sumNum(i, j) << endl;
        }catch(int){
            throw runtime_error("bad code");
        }
    }

    //assert(i > 0);
    //cout << i + j << endl;
    return 0;
}
