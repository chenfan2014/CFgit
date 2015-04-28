#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

/* 
 * 我们在这个问题要设置三个指针，current, begin, end
 * 1. current指针遍历整个数组序列，current指向1的时候，current ++
 * 2. curr指向2的时候，此时用end指针和curr换，end --
 * 3. 然后我们的begin是指向1的，我们把begin和curr交换，然后begin++ curr ++
 */

int *FlagOfNetherlands(int arr[], int size)
{
    if(size == 0){
        return arr;
    }
    int begin = 0;  
    int end = size - 1;
    int curr = 0;

    while(curr <= end)
    {
        while(arr[end] == 2){
            end --;
        }
        while(arr[begin] == 0){
            begin ++;
        }
        while(arr[curr] == 0 || arr[curr] == 1){
            curr ++;
        }
        //这个时候我们的end指向0， begin指向1， curr指向2 
        if(arr[curr] == 2 && curr <= end){     //这个时候arr[curr]和我们的arr[end]交换
            arr[curr] = arr[end];
            arr[end] = 2;
            end --;
        }

        if(arr[begin] == 1 && arr[end] == 0){
            arr[begin] = 0;
            arr[end] = 1;
        }
         
        if(arr[curr] == 0){
            arr[curr] = arr[begin];
            arr[begin] = 0;
            curr ++;
            begin ++;
        }else{
            curr ++;
        }


        for (int i = 0; i < size; i++) {
            cout << arr[i] << " " ;
        }
        cout << endl;
    }

    return  arr;
}

int main(int argc, const char *argv[])
{
    int array [] = {0, 2, 1, 1, 2, 0, 2, 1};
    int size = sizeof(array)/sizeof(int);
    int *afterArr = new int[size];
    afterArr = FlagOfNetherlands(array, size);
    for (int i = 0; i < size; i++) {
        cout << afterArr[i] << " " ;
    }
    cout << endl;
    return 0;
}
