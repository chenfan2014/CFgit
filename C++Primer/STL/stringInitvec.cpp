#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char *argv[])
{
    string sarr[] = {"beijing", "shanghai", "guangzhou", "shenzhen"};
    vector<string> vec(sarr, sarr + 3);
    for(vector<string>::iterator it = vec.begin(); it != vec.end(); ++it){
        cout << *it << endl;    
    }
    return 0;
}
