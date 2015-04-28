#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> findRepeatedDNA(string s)
{
    map<string, int> smap;
    string s2;
    for(int i = 0; i != s.size() - 9; i ++)
    {
        s2 = s.substr(i, 10);
        ++smap[s2];
    }

    vector<string> svec;
    for(map<string, int>::iterator it = smap.begin(); it != smap.end(); it ++)
    {
        if(it -> second >= 2){
            svec.push_back(it -> first);
        }
    }
    return svec;
}

int main(int argc, const char *argv[])
{
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTTAAAAGGGTTT";
    vector<string> sv = findRepeatedDNA(s);
    for(vector<string>::iterator it = sv.begin(); it != sv.end(); ++it){
        cout << *it << endl;  
    }   
    return 0;
}
