#include <iostream>
#include <string>
#include <vector>
#include <signal.h>
#include <errno.h>
#include <assert.h>
using namespace std;

inline bool SIGBAG(int signo){
    assert(signo <= 0 || signo >= NSIG);
}

int main(int argc, const char *argv[])
{
    int a;
    cin >> a;
    if(!SIGBAG(a)){
        cout << "Yes" << endl;
    }else{
        cout << "Wrong" << endl;
    }
    return 0;
}
