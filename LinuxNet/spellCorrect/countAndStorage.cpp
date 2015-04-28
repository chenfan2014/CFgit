#include "header.h"
using namespace std;
int main(int argc, const char *argv[])
{
    string s1, s2;
    while(cin >> s1 >> s2){
        cout << editDistance(s1, s2, s1.size() - 1, s2.size() -1) << endl;
    }
    ifstream readFile("Apple.txt");
    ofstream outFile("AppleCopy.txt");
    if(!readFile){                      //打开文件失败，则执行
        ERR_EXIT("error readfile");
    }
    
    string word;
    map<string, int> wordCount;
    while(readFile >> word){
        for(int i = 0; i != word.size(); i ++){
            upToLower(word[i]);
            if(ispunct(word[i]) || isdigit(word[i]) || isspace(word[i])){
                word.erase(i, 1);
                i --;
            }
        }
        wordCount[word] ++;
    }
    for(map<string, int>::iterator it = wordCount.begin(); it != wordCount.end(); ++it)
    {
        outFile << it -> first << " " << it -> second << endl;
    }
    readFile.close();
    outFile.close();
    return 0;
}
