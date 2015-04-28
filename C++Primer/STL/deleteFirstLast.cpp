#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;
int main(int argc, const char *argv[])
{
    vector<string> svec;
    svec.push_back("beijing");
    svec.push_back("shanghai");
    svec.push_back("guangzhou");
    svec.push_back("shenzhen");
    

    list<string> slist;
    slist.insert(slist.begin(), svec.begin(), svec.end());


    //svec.pop_front();
    slist.pop_back();
    for(vector<string>::iterator it = svec.begin(); it != svec.end(); ++it){
        cout << *it << endl;    
    }
    cout << "-----------------------------" << endl;

    for(list<string>::iterator it = slist.begin(); it != slist.end(); ++it){
        cout << *it << endl;    
    }
    return 0;
}
