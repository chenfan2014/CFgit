#include <iostream>
#include <string>
#include <vector>

using namespace std;
int add(int a, int b)
{
    if(b == 0){
        return a;
    }else{
        int sum = a ^ b;
        int carry = (a & b) << 1;
        return add(sum, carry);
    }
}
int addNoArithm(int a, int b)
{
    if(b == 0){
        return a;
    }else{
        int sum = a ^ b;
        int carry = (a & b) << 1;
        return addNoArithm(sum, carry);
    }
}















int main(int argc, const char *argv[])
{
    int a , b;
    while(1){
        cin >> a >> b;
        cout << add(a, b) << endl;
    }
    return 0;
}
