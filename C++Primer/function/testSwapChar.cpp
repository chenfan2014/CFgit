#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

void swap(char * &a, char * &b)
{
    char *tmp = a;
    a = b;
    b = tmp;
}

int main(int argc, const char *argv[])
{
    char *a = "Beijing";
    char *b = "shanghai";
    
    swap(a, b);
    cout << a << " " << b << endl;
    return 0;
}
