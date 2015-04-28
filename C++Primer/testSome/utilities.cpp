#include <iostream>
#include <string>
#include <vector>
template<typename T>
int compare(const T &lval, const T &rval){
    if(lval < rval){
        return 1;
    }else if(rval < lval){
        return -1;
    }else{
        return 0;
    }
}

int main(int argc, const char *argv[])
{
    
    return 0;
}
