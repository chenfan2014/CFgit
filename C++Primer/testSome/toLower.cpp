#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
using namespace std;

void toLower(char *str)
{
    assert(str != NULL);
    while(*str){
        if(*str >= 'A' && *str <= 'Z'){     //这里>=的优先级比逻辑与&&的优先级高，而解引用*的优先级比>=要高
            *str += 'z' - 'Z';
        }
        str ++;
    }
}

int main(int argc, const char *argv[])
{
    char *s;
    while(1){
        cin >> s;
        toLower(s);
        cout << s << endl;
    }
    return 0;
}
