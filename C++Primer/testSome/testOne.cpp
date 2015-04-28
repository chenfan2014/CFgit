#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
int main(int argc, const char *argv[])
{
    int arr[] = {0, 1, 2, 3, 4, 5, 1, 1, 1, 1, 1, 1, 1, 1};
    int ret = sizeof(arr)/sizeof(int);

    vector<int> vec;        //用来存放我们已经查找过的数字;
    int i;
    int count = 0;

    for(i = 0; i != (ret + 1)/2; i ++){
        vector<int>::iterator it = find(vec.begin(), vec.end(), arr[i]);
        if(it == vec.end()){
            vec.push_back(arr[i]);      //如果vector当中没有这个数字,我们把他放入vector,然后再进行次数计算
            
            int num = arr[i];
            count = 0;
            for(int j = 0; j != ret; j ++){
                if(num == arr[j]){
                    count ++;
                }
            }

            if(count >= (ret + 1)/2){
                cout << "num is " << num << endl;
                break;
            }
        }else if(it != vec.end()){
            continue;
        }
    }
    
    if(i == (ret + 1)/2){
        cout << "No such a number here" << endl;
    }
    return 0;
}

