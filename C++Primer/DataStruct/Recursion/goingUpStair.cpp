#include <iostream>
#include <string>
#include <vector>

using namespace std;

int upStair(int n)
{
    if(n == 0 || n == 1){
        return 1;
    }else{
        return upStair(n - 1) + upStair(n - 2);
    }
}

int main(int argc, const char *argv[])
{
    int n;
    while(1){
        cin >> n;
        cout << upStair(n) << endl;
    }
    return 0;
}
