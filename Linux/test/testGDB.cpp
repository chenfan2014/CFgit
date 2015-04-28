#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct INOUT{
    int value;
    int result;
};

static int sum(int value){
    int result = 0;
    int i = 0;
    for (i = 0; i < value; i++) {
       result += i; 
    }
    return result;
}

int main(int argc, const char *argv[])
{
    struct INOUT *io = (struct INOUT *) malloc (sizeof(struct INOUT));

    if(NULL == io){
        cout << "error get memory" << endl;
    }
    if(argc != 2){
        cout << "error args" << endl;
    }
    io -> value = *argv[1] - '0';
    io -> result = sum(io -> value);

    cout << "The value you input is  : " << io -> value << endl << " the result is  : " << io -> value << endl;
    return 0;
}
