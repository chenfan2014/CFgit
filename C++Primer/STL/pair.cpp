#include <iostream>
#include <string>
#include <vector>
#include <utility>      //pair的头文件
using namespace std;
int main(int argc, const char *argv[])
{
    pair <int, string> stuPair;
    stuPair = make_pair(1, "chenfan");
    stuPair = make_pair(2, "lin");
    cout << stuPair.first << "  "  << stuPair.second << endl;
    return 0;
}
