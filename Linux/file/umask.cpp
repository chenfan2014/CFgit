#include <iostream>
#include <string>
#include <vector>
#include <fcntl.h>
#include <sys/stat.h>
#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)
using namespace std;

int main(int argc, const char *argv[])
{
    umask(0);
    if(creat("foo", RWRWRW) < 0){
        cout << "err foo" << endl;
    }else{
        cout << "success foo " << endl;
    }
    umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    if(creat("bar", RWRWRW) < 0){
        cout << "err bar" << endl;
    }else{
        cout << "success bar" << endl;
    }
    return 0;
}
