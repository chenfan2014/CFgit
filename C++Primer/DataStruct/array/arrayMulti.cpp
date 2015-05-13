#include <iostream>
#include <string>
#include <vector>

using namespace std;

//问题：输入一个长度为n的整数数组，树吃一个长度为n的数组，这个数组满足每一个元素为原来数组除了当前位置值其他位置值的积
//要求具有现行复杂度，也就是O(N).不能使用除法运算符
//我们使用两个辅助数组，一个存储我们元素左边的乘积，一个存储我们元素右边的乘积，然后计算结果

void muitiArray(int arr[], int size)         
{
    int left[size];
    int right[size];

    left[0] = 1;
    right[size - 1] = 1;
    for(int i = 1; i != size; i ++){
        left[i] = arr[i - 1] * left[i - 1];
    }
    
    for(int i = size - 2; i >= 0; i --){
        right[i] = arr[i + 1] * right[i + 1];
    }

    for(int i = 0; i != size; i ++){
        arr[i] = left[i] * right[i];
    }
}

int main(int argc, const char *argv[])
{
    int arr[] = {2, 3, 4, 5};
    for(int i = 0; i != sizeof(arr)/sizeof(int); i ++){
        cout << arr[i] << " ";
    }
    cout << endl << "------------------------------" << endl;
    muitiArray(arr, sizeof(arr)/sizeof(int));
    for(int i = 0; i != sizeof(arr)/sizeof(int); i ++){
        cout << arr[i] << " ";
    }
    cout << endl << "------------------------------" << endl;
   

    return 0;
}
