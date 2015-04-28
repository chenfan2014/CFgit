#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
int main(int argc, const char *argv[])
{
    int arr[] = {1, 2, 5, 8, 10, 9, 4, 3, 6, 7};
    int size = sizeof(arr)/sizeof(int);
    map<int, int> imap;
    for(int i = 0; i != size; i ++){
        imap[arr[i]] = i;
    }
    for(map<int,int>::iterator it = imap.begin(); it != imap.end(); ++it)
    {
        cout << it -> first << " ";
    }
    cout << endl;
    int flag;
    int loc;
    for(map<int,int>::iterator it = imap.begin(); it != imap.end(); ++it)
    {
        map<int, int>::iterator it2 = it;
        if(it -> second < (++it2) -> second){       //后面的下标大,这个时候我们直接输出内容
            cout << it -> first << endl;
            flag = 0;
        }else{                                  //否则的话，就是后面的下标小
            if(flag == 0){          //说明我们这个元素之前是endl了，我们把flag设置为1
                flag = 1;
                loc = it -> second; 
            }
            if(it -> second <= loc){
                cout << it -> first << ",";
            }
        }
    }
    cout << endl;
    
    return 0;
}
