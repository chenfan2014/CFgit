#include <iostream>
#include <string>
#include <vector>
using namespace std;

int countBinaryOne(unsigned int n)
{
   int count = 0;
   while(n > 0){
       n = n & (n - 1);
       count ++;
   }
   return count;
}

int main(int argc, const char *argv[])
{
    int num;
    while(1){
        cin >> num;
        cout << countBinaryOne(num) << endl;
    }
    return 0;
}
