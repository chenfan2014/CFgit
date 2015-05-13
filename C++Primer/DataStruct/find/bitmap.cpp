#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int bitWord = 32;
const int shift = 5;
const int N = 100000;

#define MASK 0x1F

int a[1 + N/bitWord];

void set(int i){        //将第i为设置为1
    a[i >> shift] |= (1 << (i & mask));
}

void clr(int i){        //将第i为设置为0
    a[i >>shift] &= ~(1 << (i & mask));
}


int main(int argc, const char *argv[])
{
    
    return 0;
}
