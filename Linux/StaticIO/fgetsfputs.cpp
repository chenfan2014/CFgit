#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int main(int argc, const char *argv[])
{
    char buf[4] = "0";
    while(fgets(buf, 4, stdin) != NULL){
        fputs(buf, stdout);
    }
    return 0;
}
