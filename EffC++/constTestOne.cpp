#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
const operator * (int lhs, int rhs){
    return lhs * rhs;
}
*/
int main(int argc, const char *argv[])
{
    int lhs, rhs;
    int other;
    lhs = 10;
    rhs = 20;
    other = 30;
    (lhs * rhs) = other;
    
    return 0;
}
