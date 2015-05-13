#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

int main(int argc, const char *argv[])
{
    const char *str = "Beijing";
    //char *s = const_cast<char *>(str);
    char *s("Beijing");
    cout << s << endl;
    strcpy(s, "beijin");
    cout << s << endl;
    return 0;
}
