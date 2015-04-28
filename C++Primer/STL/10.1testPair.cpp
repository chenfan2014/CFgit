#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;
struct Test{
    int id_;
    string name_;
};
int main(int argc, const char *argv[])
{
    vector< pair<int, string> > stuTest;
    pair<int ,string> stuPair;
    int first;
    string second;
    while(cin >> first >> second){
        stuPair = make_pair(first, second);
        stuTest.push_back(stuPair);
    }
    
    vector< pair<int, string> >::size_type ix;
    for(ix = 0; ix != stuTest.size(); ++ix){
        cout << stuTest[ix].first << " " << stuTest[ix].second << endl;
    }
    
    for(vector< pair<int ,string> >::iterator it = stuTest.begin(); it != stuTest.end(); ++it){
        cout << it -> first << "     " <<  it -> second << endl;
    }

    return 0;
}
