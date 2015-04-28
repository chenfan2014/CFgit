#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, const char *argv[])
{
    vector<string> svec;
    cout << svec.size() << endl;
    if(svec.empty()){
        cout << "this is an empty vector" << endl;
    }
    svec.push_back("beijing");
    svec.push_back("shanghai");
    svec.push_back("guangzhou");
    svec.push_back("shenzhen");
    svec.push_back("nanchang");
    svec.push_back("fuzhou");
    svec.push_back("xian");
    svec.push_back("hangzhou");
    svec.push_back("jinan");
    cout << svec.size() << endl;
    if(svec.empty()){
        cout << "this is an empty vector" << endl;
    }
    cout << "Capacity : " << svec.capacity() << endl;
    svec.resize(12);
    for(vector<string>::iterator it = svec.begin(); it != svec.end(); ++it){
        cout << *it << endl;    
    }
    string sfind;
    while(cin >> sfind){
        vector<string>::iterator iter = find(svec.begin(), svec.end(), sfind.c_str());
        if(iter != svec.end()){
            cout << *iter << endl;
        }else{
            cout << "No this element" << endl;
        }
    }
    return 0;
}
