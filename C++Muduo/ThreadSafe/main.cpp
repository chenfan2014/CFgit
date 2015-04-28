#include "threadSafe.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char *argv[])
{
    Counter c = new Counter();
    int64_t num = c.value();
    cout << num << endl;
    return 0;
}
