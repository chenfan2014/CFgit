#include <iostream>
#include <string>
#include <vector>
#include <stdint.h>
using namespace std;

int hammingWeight(uint32_t n)
{
    int count = 0;
    int i = 1;
    uint32_t number = 1;
    while(i != 32){
        int get = 0;
        get = n & number;
        if(get != 0){
            count ++;
        }
        i ++;
        number = number << 1;
    }
    return count;
}

int main(int argc, const char *argv[])
{
    uint32_t n = 11;
    cout << hammingWeight(n) << endl;
    return 0;
}
