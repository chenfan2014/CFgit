#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, const char *argv[])
{
    vector<string> svec;
    string str;
    while(cin >> str){
        svec.push_back(str);
    }

    sort(svec.begin(), svec.end());
    vector<string>::iterator endUnique = unique(svec.begin(), svec.end());
    svec.erase(endUnique, svec.end());

    for(vector<string>::iterator it = svec.begin(); it != svec.end(); ++it){
        if((*it).size() >= 4){
            cout << *it << " ";
        }
    }
    
    cout << endl;
    return 0;
}
