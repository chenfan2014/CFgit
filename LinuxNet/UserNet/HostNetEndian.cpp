#include <iostream>
#include <arpa/inet.h>
using namespace std;

const int BITS16 = 16;
const int BITS32 = 32;

typedef union{
    unsigned short int value;
    unsigned char byte[2];
}to16;

typedef union{
    unsigned long int value;
    unsigned char byte[4];
}to32;

void showValue(unsigned char *begin, int flag){
    int num = 0;
    int i = 0;
    if(flag == BITS16){
        num = 2;
    }else if(flag == BITS32){
        num = 4;
    }
    
    for(i = 0; i != num; i ++){
        cout << *(begin + i) << "  ";
    }
    cout << endl;
}

int main(int argc, const char *argv[])
{
    to16 first16, second16, third16;
    to32 first32, second32, third32;

    first16.value = 0xabcd;
    second16.value = htons(first16.value);
    third16.value = htons(second16.value);
    
    first32.value = 0x12345678;
    second32.value = htons(first32.value);
    third32.value = htons(second32.value);
    
    cout << first16.byte[0] << endl;
    showValue(first16.byte, BITS16);

    return 0;
}
