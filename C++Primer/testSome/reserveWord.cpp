#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <assert.h>
using namespace std;

void reserveWord(char *beg, char *end)
{
    assert(beg != NULL && end != NULL);
    while(beg < end){
        char tmp = *beg;
        *beg = *end;
        *end = tmp;
        beg ++;
        end --;
    }
}

char *reserveSentence(char *sent)
{
    reserveWord(sent, sent + strlen(sent) - 1);
    int i, j;
    i = j = 0;
    int k;
    
    for(k = 0; k != strlen(sent) + 1; k ++)
    {
        if(sent[k] != ' '){
            j ++;
        }
        if(sent[k] == ' '){
            reserveWord(sent + i,sent + j - 1);
            j ++;
            i = j;
        }
        if(sent[k] == '\0'){
            reserveWord(sent + i, sent + strlen(sent) - 1);
        }
    }

    return sent;
}

int main(int argc, const char *argv[])
{
    char s[] = "South China Normal University";
    cout << "Before : " << s << endl;
    cout << "After : "  <<  reserveSentence(s) << endl;
    return 0;
}
