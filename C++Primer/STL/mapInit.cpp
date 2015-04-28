#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
int main(int argc, const char *argv[])
{
    map<int, string> stuMap;
    stuMap[1] = "chenfan";
    stuMap[6] = "lilin";
    stuMap[4] = "scnu";
    stuMap[4] = "changsha";
    stuMap.insert(make_pair(5, "chongqing"));
    stuMap.insert(make_pair(6, "chongqing"));
    for(map<int, string>::iterator it = stuMap.begin(); it != stuMap.end(); ++it){
        cout << it -> first << "   " << it -> second << endl;    
    }
    cout << "No this element "<< stuMap[3] << endl;
    for(map<int, string>::iterator it = stuMap.begin(); it != stuMap.end(); ++it){
        cout << it -> first << "   " << it -> second << endl;    
    }
    return 0;
}
