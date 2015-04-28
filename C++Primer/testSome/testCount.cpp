#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
int main(int argc, const char *argv[])
{
    vector<int> ivec;
    list<string> svec;
    ivec.push_back(9);
    ivec.push_back(9);
    ivec.push_back(9);
    ivec.push_back(9);
    ivec.push_back(9);
    ivec.push_back(9);
    ivec.push_back(9);
    svec.push_back("SCNU");
    svec.push_back("SCNU");
    svec.push_back("SCNU");
    svec.push_back("SCNU");
    svec.push_back("SCNU");
    svec.push_back("SCNU");
    cout << count(ivec.begin(), ivec.end(), 9) << endl;
    cout << count(svec.begin(), svec.end(), "SCNU") << endl;
    return 0;
}
