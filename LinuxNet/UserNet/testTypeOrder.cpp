#include <stdio.h>
typedef union{
    unsigned short int value;
    unsigned char byte[2];
}to;

int main(int argc, const char *argv[])
{
    to typeOrder;
    typeOrder.value = 0xabcd;

    if(typeOrder.byte[0] == 0xcd && typeOrder.byte[1] == 0xab){
        printf("This is Little Endian\n");
    }
    if(typeOrder.byte[0] == 0xab && typeOrder.byte[1] == 0xcd){
        printf("This is Big Endian\n");
    }
    return 0;
}
