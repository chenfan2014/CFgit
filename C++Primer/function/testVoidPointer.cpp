#include <iostream>
#include <string>
#include <vector>

using namespace std;


void *voidPointer(char *str) 
{
    //return str;
}

int main(int argc, const char *argv[])
{
    char *a = "Beijing";
    voidPointer(a);
    return 0;
}
