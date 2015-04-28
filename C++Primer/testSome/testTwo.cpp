#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;
int compare(char *src, const char *dest)
{
    int len = strlen(dest);
    char mid[len + 1];
    memset(mid, 0, len + 1);
    
    for(int i = 0; i != strlen(src) - len  + 1; i ++){
        char *p = src;
        p += i;
        strncpy(mid, p, len);
        cout << mid << endl;
        if(strcmp(mid, dest) == 0){
            return 1;
        }
    }
    return 0;
}
int main(int argc, const char *argv[])
{
    char *src = "chinaisgood";
    char *dest = "ood";
    cout << compare(src, dest) << endl;
}   
