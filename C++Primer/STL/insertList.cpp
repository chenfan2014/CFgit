#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;
int main(int argc, const char *argv[])
{
    list<string> slist;
    slist.push_back("beijng");
    slist.push_back("shanghai");
    slist.push_front("guangzhou");
    slist.insert(slist.begin(), "shenzhen");
    slist.insert(slist.begin(), 10, "hangzhou");
    for(list<string>::iterator it = slist.begin(); it != slist.end(); ++it){
        cout << *it << endl;    
    }   
    return 0;
}
