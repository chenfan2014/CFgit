#include <iostream>
#include <string>
#include <vector>
using namespace std;

int addNoArithm(int lnum, int rnum){
    if(lnum == 0){
        return rnum;
    }

    int sum = lnum ^ rnum;    
    int carry = (lnum & rnum) << 1;
    return addNoArithm(sum, carry);
}

int main(int argc, const char *argv[])
{
    int a = 0;
    int b = 8;
    cout << addNoArithm(a, b) << endl;
    return 0;
}
