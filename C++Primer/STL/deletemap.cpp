#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
int main(int argc, const char *argv[])
{
    map<string, int> smap;
    smap["beijing"] = 8; 
    smap["shanghai"] = 2; 
    smap["guangzhou"] = 3; 
    smap["shenzhen"] = 5; 
    smap["xian"] = 4; 
    smap["chengdu"] = 1;
    for(map<string, int>::iterator it = smap.begin(); it != smap.end(); ++it){
        cout << it -> first << " " << it -> second << endl;
    }

    cout << "-------------------------------" << endl;
    smap.erase("chengdu");
    for(map<string, int>::iterator it = smap.begin(); it != smap.end(); ++it){
        cout << it -> first << " " << it -> second << endl;
    }

    cout << "-------------------------------" << endl;
    map<string, int>::iterator it = smap.begin();
    smap.erase(it);
    for(map<string, int>::iterator it = smap.begin(); it != smap.end(); ++it){
        cout << it -> first << " " << it -> second << endl;
    }
    
    cout << "-------------------------------" << endl;
    map<string, int>::iterator first = smap.find("guangzhou");
    map<string, int>::iterator second = smap.find("xian");
    smap.erase(first, second);
    for(map<string, int>::iterator it = smap.begin(); it != smap.end(); ++it){
        cout << it -> first << " " << it -> second << endl;
    }

    return 0;
}
