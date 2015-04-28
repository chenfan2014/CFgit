#include <iostream>
#include <string>
#include <vector>
using namespace std;
int func(vector<int> ivec)
{
    static int k = 2;

    vector<int>::reverse_iterator it;
    for(it = ivec.rbegin(); it != ivec.rend(); ++it)
    {
        cout << "*it : " << *it << endl; 
        k += *it % 2 == 0 ? ++*it : (*it) ++;
    }
    return k;
}
int main(int argc, const char *argv[])
{
    vector<int> ivec;
    for(int i = 0; i != 4; i ++){
        ivec.push_back(i);
        cout << func(ivec) << endl;
    }
    return 0;
}
