#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;


template<typename A, typename B>
int compare(const A &lval, const B &rval){
    return lval > rval ? 1 : 0;
}

/*
template<>
int compare<const char *>(const char *const &v1, const char *const &v2){
    return strcmp(v1, v2);
}
*/

int main(int argc, const char *argv[])
{

    cout << compare("China", "Chin") << endl;
    cout << compare<std::string>("China", "Chinaa") << endl;
    cout << compare(static_cast<std::string>("china"), static_cast<std::string>("China")) << endl;
    const char *a = "beijing";
    const char *b = "shanghai";
    cout << compare(a, b) << endl;
    return 0;
}
