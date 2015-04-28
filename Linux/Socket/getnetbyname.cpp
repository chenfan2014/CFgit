#include <iostream>
#include <string>
#include <vector>
#include <netdb.h>

using namespace std;

int main(int argc, const char *argv[])
{
    struct netent *net;
    struct hostent *host;
    const char *name = "www.baidu.com";
    
    net = getnetbyname(name);
    host = gethostbyname(name);
    cout << host -> h_name << endl;
    //cout << net -> n_name << endl;
    cout << host -> h_addr_list[0] << endl; 
    
    return 0;
}
