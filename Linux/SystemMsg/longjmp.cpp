#include <iostream>
#include <string>
#include <vector>
#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

static void f1(int, int, int, int, int);
static void f2(void);

static jmp_buf jmpbuffer;
static int globval;

int main(int argc, const char *argv[])
{
    int autoval;
    register int regival;
    volatile int volaval;
    static int statval;

    globval = 1;
    autoval = 2;
    regival = 3;
    volaval = 4;
    statval = 5;

    if(setjmp(jmpbuffer) != 0){
        cout << "After long jmp : " << endl;
        cout << globval << " " << autoval << " " << regival << " " << volaval << " "<< statval << endl;
        exit(0);
    }

    globval = 11;
    autoval = 22;
    regival = 33;
    volaval = 44;
    statval = 55;
    f1(globval, autoval, regival, volaval, statval);

    return 0;   
}

static void f1(int v1, int v2, int v3, int v4, int v5){
    cout << "In f1" << endl;
    cout << v1 << " " << v2 << " " << v3 << " " << v4 << " " << v5 << endl;
    f2();
}

static void f2(void){
    longjmp(jmpbuffer, 1);
}
