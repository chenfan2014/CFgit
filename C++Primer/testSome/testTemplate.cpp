#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
int compare(const T &lval, const T &rval){
    return lval > rval ? 1 : 0;
}


template <typename T>
void Swap(T &lval, T &rval){
    T val = lval;
    lval = rval;
    rval = val;
}

int main(int argc, const char *argv[])
{
    cout << compare(7, 9) << endl;
    cout << compare('a', 'A') << endl;
    cout << compare(string("china"), string("chin")) << endl;

    char a = 'a';
    char b = 'b';
    Swap(a, b);
    cout << "a = " << a << " b = " << b << endl;

    return 0;

}

