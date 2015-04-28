#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char *argv[])
{
    int i = 81;
    while(i --){
        if(i / 9 % 3 == i % 9 % 3){
            continue;
        }else{
            cout << i / 9 + 1 << ","  << i % 9 + 1 << "  ";
        }
    }
    return 0;
}
