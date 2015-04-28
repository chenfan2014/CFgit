#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char *argv[])
{
    vector<int> ivec;
    
    for(string::size_type i = 0; i != 10; i ++){
        ivec.push_back(i);
    }
    for(vector<int>::iterator it = ivec.begin(); it != ivec.end(); ++it){
        cout << *it << endl;    
    }
    
    ivec.resize(12, 2);
    cout << "--------------" << endl;
    for(vector<int>::iterator it = ivec.begin(); it != ivec.end(); ++it){
        cout << *it << endl;    
    }
    ivec.resize(5);
    cout << "--------------" << endl;
    for(vector<int>::iterator it = ivec.begin(); it != ivec.end(); ++it){
        cout << *it << endl;    
    }
    
    cout << "New Begin --------------" << endl;
    vector<int>::reference rbeg = ivec.front();
    cout << rbeg << endl;
    
    vector<int>::reference rbegT = *ivec.begin();
    cout << rbegT << endl;

    vector<int>::reference rend = *(ivec.end() - 1);
    //vector<int>::reference rend = *--ivec.end(); 结果一样
    cout << rend << endl;

    vector<int>::reference rendT = ivec.back();
    cout << rendT << endl;


    return 0;
}
