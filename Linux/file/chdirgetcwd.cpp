#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <stdlib.h>
using namespace std;
char *path_alloc(size_t *size)
{
    char *p = NULL;
    if(!size){
        return NULL;
    }
    p = (char *)malloc(256);
    if(p){
        *size = 256;
    }else{
        *size = 0;
    }
    return p;
}
int main(int argc, const char *argv[])
{
    char *ptr;
    size_t size;
    if(chdir("/home/cf") < 0){
        cout << "error path" << endl;
    }
    ptr = path_alloc(&size);
    if(getcwd(ptr, size) == NULL){
        cout << "failed to get " << endl;
    }else{
        cout << ptr << endl;
    }
    return 0;
}
