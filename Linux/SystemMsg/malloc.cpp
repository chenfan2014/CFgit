#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <string.h>
using namespace std;
int main(int argc, const char *argv[])
{
    char *buf;
    buf = (char *)malloc(10);
    cout << strlen(buf) << endl;
    while(cin >> buf){
        cout << buf << endl;
    }
    return 0;
}
