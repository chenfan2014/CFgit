#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
int main(int argc, const char *argv[])
{
    string s = "beijing";
    s.insert(2, 5, 's');
    cout << s << endl << "---------------------------" << endl;
    
    s = "beijing";
    s.insert(3, "test");
    cout << s << endl << "---------------------------" << endl;

    s = "beijing";
    string str = "shanghai";
    s.insert(0, str);
    cout << s << endl << "---------------------------" << endl;

    s = "beijing";
    s.erase(2, 3);
    cout << s << endl << "---------------------------" << endl;

    s = "beijing  shanghai";
    str = s.substr(1, 7);
    cout << str << endl << "---------------------------" << endl;

    s = "beijing";
    s.append("shanghai", 4);
    cout << s << endl << "---------------------------" << endl;
    return 0;
}
