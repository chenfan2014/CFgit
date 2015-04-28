#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <string.h>
using namespace std;
int main(int argc, const char *argv[])
{

    //char str[100] = " ";
    string str;
    str = "beijing city";
    //strcpy(str, "beijing is a beautiful city\n");
    size_t n = str.size();
    write(1, str.c_str(), str.size());
    return 0;
}
