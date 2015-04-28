#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct LNode{
    int value;
    LNode *next;
};

struct Stack{
    LNode *top;
    int size;       
};

Stack *initStack()
{
    Stack st = (Stack *)malloc(sizeof(Stack));
    if(st != NULL){
        st -> top =  NULL;
        st -> size = 0;
    }
    return st;
}

int main(int argc, const char *argv[])
{
    
    return 0;
}
