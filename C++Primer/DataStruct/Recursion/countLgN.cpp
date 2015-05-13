#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

extern int factorial(int n);

double countLogN(int n)
{
    double total = factorial(n);
    cout << total << " Result : ";
    return log(total)/log(2);
}

int main(int argc, const char *argv[])
{
    int n;
    while(1)
    {
        cin >> n;
        cout << countLogN(n) << endl;
    }
    return 0;
}
