#include <iostream>
#include <string>
#include <vector>
using namespace std;

int *mergeArray(int arr1[], int arr2[], int s1, int s2)
{
    int *arr = new int[s1 + s2];
    if(s1 == 0){
        return arr2;
    }
    if(s2 == 0){
        return arr1;
    }
    
    int i = 0, j = 0;
    int k = 0;
    while(1){       //这就是说我们数组的元素都不为NULL
        if(i == s1 || j == s2){     //也就是说某一个数组已经全部插入，那么我们对另一个数组剩下元素全部插入
            break;
        }
        if(arr1[i] > arr2[j]){       //第一个元素值大,那么我们把arr2的值赋值给arr，然后让指针指向下一个元素
            arr[k ++] = arr2[j ++];
        }else{
            arr[k ++] = arr1[i ++];
        }
    }
    if(i <= s1 - 1){    //所有的都放进去了
        for(; i != s1 - 1; i ++){
            arr[k] = arr[i];
        }
    }
    if(j <= s2 - 1){
        while(j != s2){
            arr[k ++] = arr2[j ++];
        }
    }
    
    return arr;
}

int main(int argc, const char *argv[])
{
    int arr1[] = {1, 3, 5, 6, 8, 9};
    int arr2[] = {2, 4, 7, 11, 12, 23, 43};
    int size = (sizeof(arr1) + sizeof(arr2))/sizeof(int);
    int *mergeArr = new int[size]();    //定义动态数组

    mergeArr = mergeArray(arr1, arr2, sizeof(arr1)/sizeof(int), sizeof(arr2)/sizeof(int));
    //mergeArr = mergeArray(arr1, arr2, sizeof(arr1)/sizeof(int), 0);
    for(int i = 0; i != size; i ++)
    {
        cout << mergeArr[i] << " ";
    }
    
    cout << endl;
    return 0;
}
