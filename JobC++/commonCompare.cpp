#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <assert.h>
using namespace std;
/*
 *这里的字串的后面的，前面的是我们的总体串
 */
bool commomCompare(const char *lstr, const char *rstr){
    int llen = strlen(lstr);
    int rlen = strlen(rstr);
    assert(llen > rlen);
    for(int i = 0; i != llen - rlen + 1; i ++){
        int j = 0;
        for(; j != rlen - 1;j ++){
            if(lstr[i + j] != rstr[j]){
                break;
            }
        }
        if(j == rlen){
            return true;
        }else{
            j = 0;
            continue;
        }
    }
    return false;
}
int main(int argc, const char *argv[])
{
    char *ls = "zhongguo";
    char *rs = "zhong";
    cout << commomCompare(ls, rs) << endl;
    return 0;
}
