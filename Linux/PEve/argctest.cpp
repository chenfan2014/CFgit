#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char *argv[])
{
    if(argc < 2){
        cout << "too few args" << endl;
    }else{
        for(int i = 0; i != argc; i ++){
            cout << "argv[" << i << "] : "<<argv[i] << endl;
        }
    }
    return 0;
}
