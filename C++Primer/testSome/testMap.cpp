#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
using namespace std;
int main(int argc, const char *argv[])
{
    ifstream infile;
    string s;
    map<string, int> wordCount;
    infile.open("test.txt");
    if(!infile){
        cerr << "error open" << endl;
    }
    
    while(infile >> s){
        wordCount[s] ++;
    }
    
    cout << "-------------"<< endl;
    map<string, int>::const_iterator mapIt = wordCount.begin();
    while(mapIt != wordCount.end()){
        cout << "Word : " << mapIt -> first << " Times : "  << mapIt -> second << endl;
        ++mapIt;
    }
    
    cout << "----------------------------" << endl;
    int occur = 0;
    string str;
    map<string, int>::iterator it = wordCount.begin();
    it ++;
    it ++;
    str = it -> first;
    cout << str << endl;
     
    cout << wordCount.count("China") << endl;
    cout << " ------------" << endl;
    infile.close();
    
    return 0;
}
