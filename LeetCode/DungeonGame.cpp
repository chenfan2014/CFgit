#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
#include <algorithm>
using namespace std;

int calcMinHP(vector<vector<int> > &ivec)
{
    int m = ivec.size();
    int n = ivec[0].size();  //这两个就是我们要走的横轴和纵轴
    
    ivec[m - 1][n - 1] = max(0 - ivec[m - 1][n - 1], 0);//最后一个元素
    for(int i = m - 2; i >= 0; i --)
    {
        ivec[i][n - 1] = max(ivec[i + 1][n - 1] - ivec[i][n - 1], 0);
    }
    for(int j = n - 2; j >= 0; j --)
    {
        ivec[m - 1][j] = max(ivec[m - 1][j + 1] - ivec[m - 1][j], 0);
    }

    for(int i = m - 2; i >= 0; --i)
    {
        for(int j = n - 2; j >= 0; --j)
        {
            ivec[i][j] = max(min(ivec[i][j + 1], ivec[i + 1][j]) - ivec[i][j], 0);
        }
    }
    cout << "----------------------------" << endl;
    for(vector<vector<int> >::size_type ix = 0; ix != ivec.size(); ++ix)
    {
       for(vector<int>::size_type i = 0; i != ivec[ix].size(); i ++)
       {
           cout << ivec[ix][i] << " ";
       }
       cout << endl;
    }

    cout << "----------------------------" << endl;
    return ivec[0][0] + 1;
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
    
    cout << endl << ivec.size() <<  " " << ivec[0].size() << endl << endl << endl;

    for(vector<vector<int> >::iterator it = ivec.begin(); it != ivec.end(); ++it)
    {
        for(vector<int>::iterator it2 = (*it).begin();  it2 != (*it).end(); ++it2)
        {
            cout << *it2 << " ";
        }
        cout << endl;
    }
    cout << "-----------------------" << endl;
    cout << endl << endl << endl;
    cout << calcMinHP(ivec) << endl;
    

    return 0;
}
