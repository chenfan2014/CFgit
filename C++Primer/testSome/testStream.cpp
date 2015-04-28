#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char *argv[])
{
    while(cin >> s, !cin.eof()){
        if(cin.bad()){
            throw runtime_error("IO stream is bad ");
        }
        if(cin.fail()){
            cerr << "failed input" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        cout << s << endl;
    }
    return 0;
}
