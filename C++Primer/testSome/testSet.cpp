#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>
#include <fstream>
using namespace std;
int main(int argc, const char *argv[])
{
    ifstream infile;
    infile.open("test.txt");
    if(!infile){
        cerr << "error open " << endl;
    }

    set<string> strSet;
    string s;
    while(infile >> s){
        strSet.insert(s);
    }
    for(set<string>::iterator it = strSet.begin(); it != strSet.end(); ++it){
        cout << *it << endl;
    }
    cout << "----------------" << endl;

    infile.close();
    infile.open("test.txt");
    list<string> listStr;
    while(infile >> s){
        listStr.push_back(s);
    }
    for(list<string>::iterator it = listStr.begin(); it != listStr.end(); ++it){
        cout << *it << endl;    
    }
    return 0;
}
