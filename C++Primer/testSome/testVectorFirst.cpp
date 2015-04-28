#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char *argv[])
{
    vector<int> vec(10, 2);
    
    vector<int>::iterator it = vec.begin();
    cout << *it << endl;

    cout << vec.front() << endl;

    cout << vec[0] << endl;
   
    vector<int> vec2;
    vector<int>::iterator it2 = vec2.begin();
    cout << *it2 << endl;

    cout << vec2.front() << endl;

    cout << vec2[0] << endl;
        
    return 0;
}
