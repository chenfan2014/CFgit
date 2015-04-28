#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char *argv[])
{
    vector<int> vec(10, 2);
    for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it){
        cout << *it << " ";    
    }
    cout << endl;

    vec.resize(5, -1);
    for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it){
        cout << *it << " ";    
    }           
    cout << endl;
    return 0;
}
