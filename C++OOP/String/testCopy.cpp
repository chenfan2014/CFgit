#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char *argv[])
{
    int *i = new int();
    i[0] = 0;
    i[1] = 2;
    int *j = i;

    i[0] = 2;



    cout << j[0] << " " << j[1] << endl;
    return 0;
}
