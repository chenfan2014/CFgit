#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;
int main(int argc, const char *argv[])
{
    vector<string> svec;            //构造一个空的数组，然后插入元素
    svec.push_back("beijing");
    svec.push_back("shanghai");
    svec.push_back("guangzhou");
    svec.push_back("shenzhen");

    vector<string >svector(svec);   //用一个容器初始化另一个容器
    for(vector<string>::iterator it = svector.begin(); it != svector.end(); ++it){
        cout << *it << endl;    
    }
    
    cout << "------------------------------------" << endl;
    vector<string> svec2(svec.begin(), svec.begin() + 2);   //用容器初始化另一个容器，不过指定开始和结束的位置
    for(vector<string>::iterator it = svec2.begin(); it != svec2.end(); ++it){
        cout << *it << endl;    
    }
    cout << "------------------------------------" << endl;
    vector<string> svec3(10, "test");   //初始化设定大小，然后再初始化
    for(vector<string>::iterator it = svec3.begin(); it != svec3.end(); ++it){
        cout << *it << endl;    
    }
    return 0;
}
