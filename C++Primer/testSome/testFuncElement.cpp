#include <iostream>
#include <string>
#include <vector>
using namespace std;

int compare(int a, int b)
{
    return a > b ? a : b;
}

int main(int argc, const char *argv[])
{
    cout << compare((1, 2, 3), (2, 3, 4, 5,  5, 6, 7, 7)) << endl;
    return 0;
}
