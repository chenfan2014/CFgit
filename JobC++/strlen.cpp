#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;
int main(int argc, const char *argv[])
{
    int n;
    char y[10] = "Beijing";
    char *x = y;
    n = strlen(x);
    *x = x[n];
    x ++;
    cout << x << endl;
    cout << y << endl;
    return 0;
}
