#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
    int a[] = {3, 4, 5, 6, 1, 2};
    int size = sizeof(a)/sizeof(a);
    int value = rotateArray(a, size);
    cout << value << endl;
    return 0;
}
