#include <iostream>
#include <string>
#include <vector>
using namespace std;

int calcDungeon(vector<vector<int> > &ivec)
{
    return 1;
}

int main(int argc, const char *argv[])
{
    vector<vector<int> > ivec;
    vector<int> iv1;
    vector<int> iv2;
    vector<int> iv3;
    iv1.push_back(-2);
    iv1.push_back(-3);
    iv1.push_back(3);
    iv2.push_back(-5);
    iv2.push_back(-10);
    iv2.push_back(1);
    iv3.push_back(10);
    iv3.push_back(30);
    iv3.push_back(-5);

    ivec.push_back(iv1);
    ivec.push_back(iv2);
    ivec.push_back(iv3);
    
    for(vector<vector<int> >::iterator it = ivec.begin(); it != ivec.end(); ++it)
    {
        for(vector<int>::iterator it2 = (*it).begin();  it2 != (*it).end(); ++it2)
        {
            cout << *it2 << " ";
        }
        cout << endl;
    }
    cout << "-----------------------" << endl;
    for(vector<vector<int> >::size_type ix = 0; ix != ivec.size(); ++ix)
    {
       for(vector<int>::size_type i = 0; i != ivec[ix].size(); i ++)
       {
           cout << ivec[ix][i] << " ";
       }
       cout << endl;
    }

    return 0;
}
