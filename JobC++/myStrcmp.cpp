#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
#include <string.h>
using namespace std;
int myStrcmp(const char *lstr, const char *rstr){
    assert(lstr != NULL && rstr != NULL);
    int minLen = strlen(lstr) > strlen(rstr) ? strlen(rstr) : strlen(lstr);
    int count = 0;
    while(*lstr != '\0' && *rstr != '\0'){
        if(*lstr > *rstr){
            return 1;
        }else if(*lstr < *rstr){
            return -1;
        }else{
            if(count < minLen){
                count ++;
            }
            if(count == minLen){
                if(strlen(lstr) > strlen(rstr)){
                    return 1;
                }else if(strlen(lstr) < strlen(rstr)){
                    return -1;
                }else{
                    return 0;
                }
            }
            *lstr++;
            *rstr++;
        }
    }
}
int main(int argc, const char *argv[])
{
    char *ls = "China";
    char *rs = "Chinb";
    cout << myStrcmp(ls, rs) << endl;
    cout << myStrcmp("a", "a") << endl;
    cout << myStrcmp("abc", "ab") << endl;
    return 0;
}
