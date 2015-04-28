#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
using namespace std;
int main(int argc, const char *argv[])
{
    map<string, int> wordConut;
    
    ifstream fread("words.txt");
    if(!fread){
        cout << "error open" << endl;
    }
    
    string word;
    while(fread >> word){
        wordConut[word] ++;
    }

    for(map<string, int>::iterator it = wordConut.begin(); it != wordConut.end(); ++it){
        cout << it -> first << " : " << it -> second << endl;    
    }
    return 0;
}
