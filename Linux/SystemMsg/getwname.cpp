#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stddef.h>
#include <string.h>
using namespace std;

struct passwd *
getownam(const char *name){
    struct passwd *ptr;

    setpwent();
    while((ptr = getwent()) != NULL){
        if(strcmp(name, ptr -> pw_name) == 0){
            break;
        }
        endpwent();
        return(ptr);
    }
}
int main(int argc, const char *argv[])
{
    
    return 0;
}
