#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
static void my_exit1(void);
static void my_exit2(void);
static void my_exit3(void);
int main(int argc, const char *argv[])
{
    if(atexit(my_exit12) != 0){
        cout << "can not register my_exit2" << endl;
    }
    if(atexit(my_exit11) != 0){
        cout << "can not register my_exit1" << endl;
    }
    if(atexit(my_exit31) != 0){
        cout << "can not register my_exit1" << endl;
    }
    cout << "main function is done " << endl;
    return 0;
}

static void my_exit1(void){
    cout << "first exit" << endl;
}

static void my_exit2(void){
    cout << "second exit" << endl;
}

static void my_exit3(void){
    cout << "third exit" << endl;
}


