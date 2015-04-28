#include <iostream>
#include <string>
#include <vector>
#include <netdb.h>
using namespace std;
int main(int argc, const char *argv[])
{
    struct hostent *host;
    host = gethostent();
    cout << host -> h_name << endl;
    cout << host -> h_aliases << endl;
    cout << host -> h_addrtype << endl;
    return 0;
}
