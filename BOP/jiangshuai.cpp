#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Array{
    int x;
    int y;
};
int main(int argc, const char *argv[])
{
    Array arr;
    for(arr.x = 1; arr.x != 9; ++arr.x){
        for(arr.y = 1; arr.y != 9; ++arr.y){
            if(arr.x % 3 != arr.y % 3){
                cout << arr.x << "," << arr.y <<"   ";
            }
        }
    }
    return 0;
}
