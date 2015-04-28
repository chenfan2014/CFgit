#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char *argv[])
{
    string str= "South China Normal University South China";
    cout << "First dest : " << str.find("th") << endl;
    cout << "last dest  : " << str.rfind("th") << endl;
    return 0;
}
