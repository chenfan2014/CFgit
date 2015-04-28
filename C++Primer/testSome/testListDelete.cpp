#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;
int main(int argc, const char *argv[])
{
    list<int> ilist;
    for(int i = 0; i != 10; i ++){
        ilist.push_front(i);
    }
    for(list<int>::iterator it = ilist.begin(); it != ilist.end(); ++it){
        cout << *it << endl;    
    }   
    return 0;
}
