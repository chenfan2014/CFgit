#include <iostream>
#include <string>
#include <vector>
using namespace std;

int f(int val){
    int num = 0;
    int *ptr = &num;
    cout << *ptr  << " " << ptr << endl;
    if(val == 0){
        int val = 5;
        ptr = &val;
        cout << ptr << endl; 
    }
    
    cout << ptr << endl;

    return (*ptr + 1);

}

int main(int argc, const char *argv[])
{
    int ival = 0;
    int iret = 0;
    iret = f(ival);
    cout << iret << endl;
    return 0;
}
