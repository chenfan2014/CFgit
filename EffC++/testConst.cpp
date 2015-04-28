#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;
const int MAXLEN = 1024;

int main(int argc, const char *argv[])
{
    int arr[MAXLEN];
    int a;
    int i = 0;
    while(cin >> a){
        arr[i ++] = a;
    }
    for (int j = 0; j != i; j++) {
        cout << arr[j] << "  ";
    }
    cout << endl;
    return 0;
}
