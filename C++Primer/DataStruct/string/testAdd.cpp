#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char *argv[])
{
    int i = 10;
    int j = ++ i + ++ i;      
    int k = i ++; 
    cout << j << endl;
    return 0;
}
