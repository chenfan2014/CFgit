#include <iostream>
#include <string>
#include <vector>
using namespace std;

void cal(int arr[], int result[], int n)
{
    if(n <= 0){
        return;
    }
    int i;
    result[0] = 1;      //存放结果
    for(i = 1; i != n;  ++ i){
        result[i] = result[i - 1] * arr[i - 1];
        //result[1] = result[0] * arr[0];
    }
    

    int q = 1;      //用来存储我们右边乘积
    for(i = n - 2; i != -1; --i){
        q = q * arr[i + 1];
        result[i] = result[i] * q;
    }
}


int main(int argc, const char *argv[])
{
    int arr [] = {2, 3, 4 , 5};
    int result [4];
    cout << "Begin" << endl;
    cal(arr, result, 4);
    for(int i = 0; i != 4; i ++){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
