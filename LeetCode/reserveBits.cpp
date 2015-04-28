#include <iostream>
#include <string>
#include <vector>
#include <stdint.h>
using namespace std;

uint32_t reserveBits(uint32_t n)
{
    int i = 0;
    uint32_t ret = 0;
    
    while(i != 32){
        int get = n & 1;
        ret = ((ret << 1) + get);
        if(n != 0){
            n = n >> 1;
        }
        i ++;
    }
    return ret;
}

int main(int argc, const char *argv[])
{
    uint32_t n;
    while(1){
        cin >> n;
        cout << reserveBits(n) << endl;
    }
    return 0;
}
