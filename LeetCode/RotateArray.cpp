#include <iostream>
#include <string>
#include <vector>
using namespace std;

void rotateArray(int nums[], int n, int k)
{
    int *arr = new int[2 * n];      //动态定义一个数组，大小为两倍的大小
    int i;
    for(i = 0; i != 2 * n; i ++){
        if(i < n){
            arr[i] = nums[i];
        }else{
            arr[i] = nums[i - n];
        }
    }

    int count = 0;
    while(count != k){
        
        while(i != (2 * n - i - 1)){
            arr[i] = arr[i + 1];
        }
        arr[i] = 0;
    }

}


/*
 * 这个算法我们利用了一个数组来存储我们替换的数组，然后再复制回来，时间复杂度为O(N),空间复杂度为O(N)
 */
void rotate(int nums[], int n, int k) {
    int arr[n];
    if(n == 1 || (k % n) == 0){
        for(int i = 0; i != n; i ++){
            nums[i] = nums[i];
        }
    }else{
        if(k > n){
            k = k % n;
        }
        int j = 0;
        int m = k;
        for(int i = 0; i != n; i ++){
            if(i < k){                  
                //这里表示我们把后面的K个数复制到前面Ｋ个位置
                //arr[0] = nums[n - k]; arr[1] = nums[n - k + 1]; arr[2] = nums[n  - k + 2];
                arr[i] = nums[n - m];
                m --;
            }else{
                arr[i] = nums[j ++];
            }
        }
        for(int i = 0; i != n; i ++){
            nums[i] = arr[i];
        }    
    }
}

/*
 * 第二个方法是要用到逆置，我们假设一个数组为st, 那么我们旋转之后形成数组则为ts,根据逆置ts =(st)' = (t's')'
 * 所以我们分别求出t和s的逆置，再对st进行一个大的逆置就可以了
 * 时间复杂度为O(N),空间复杂度为O(1)
 */
void reserve(int nums[], int beg, int end)
{
    while(beg < end){
        int tmp = nums[beg];
        nums[beg] = nums[end];
        nums[end] = tmp;
        beg ++;
        end --;
    }
}

void rotateArr(int nums[], int n, int k)
{
    //n = 8, k = 2
    if(k > n){
        k = k % n;
    }
    reserve(nums, 0, n - k - 1);
    reserve(nums, n - k, n - 1);
    reserve(nums, 0, n - 1);
}

int main(int argc, const char *argv[])
{
    int n, k;       //n是元素个数，k是旋转元素个数
    cin >> n >> k;
    int arr[n];
    int i = 0;
    while(i != n){
        arr[i] = i + 1;
        i ++;
    }

    rotateArr(arr, n, k);
    for(int i = 0; i != n; i ++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
