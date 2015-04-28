#include <iostream>
#include <string>
#include <vector>
using namespace std;

void numberPower(int n)
{
    if(n > 0 && (n & (n -1)) == 0)
    {
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}

void numberPowerAgain(int n)
{
    while(n > 0){
        n = n / 2;
        int ret = n % 2;
        if(n == 0 && ret == 0){
            cout << "Yes" << endl;
        }
    }
}

int main(int argc, const char *argv[])
{
    
    int num;
    while(cin >> num){
        numberPowerAgain(num);
    }
    return 0;
}
