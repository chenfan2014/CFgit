#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <string.h>
using namespace std;
int main(int argc, const char *argv[])
{
    int newfd = dup(1);
    int newfd3 = dup(0);
    char buf[] = "beijing";
    write(STDIN_FILENO, buf, strlen(buf));
    cout << newfd  << " " << newfd3 << endl;
    return 0;
}
