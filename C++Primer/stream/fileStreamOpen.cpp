#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>
using namespace std;
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)
int main(int argc, const char *argv[])
{
    ifstream fread;
    string s;
    cin >> s;
    /*
    if(!(fread.open(s.c_str() )) ) {
        ERR_EXIT("open failed");
    }*/
    if(!fread.open(s.c_str())){
        cout << "err " << endl;
    }
    while(fread >> s){
        cout << s << endl;
    }
    return 0;
}
