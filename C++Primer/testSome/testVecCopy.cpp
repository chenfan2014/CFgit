#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char *argv[])
{
    vector<int> vec(10, 2);
    vector<int> vec2;
    vec2 = vec;
    cout << vec2.size() << endl;
    for(vector<int>::iterator it = vec2.begin(); it != vec2.end(); ++it){
        cout << *it << endl;    
    }
    return 0;
}
