#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
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

   
    vector<string>::iterator vit = find(svec.begin(), svec.end(), "beijing");
    svec.erase(vit);

    vit = find(svec.begin(), svec.end(), "shenzhen");
    svec.erase(vit);
    
    list<string>::iterator sfirst = find(slist.begin(), slist.end(), "beijing");
    list<string>::iterator slast = find(slist.begin(), slist.end(), "shenzhen");
    slist.erase(sfirst, slast);
    
    slist.erase(slist.begin(), slist.end());
    
    svec.clear();

    for(vector<string>::iterator it = svec.begin(); it != svec.end(); ++it){
        cout << *it << endl;    
    }
    cout << "-----------------------------" << endl;

    for(list<string>::iterator it = slist.begin(); it != slist.end(); ++it){
        cout << *it << endl;    
    }
    return 0;
}
