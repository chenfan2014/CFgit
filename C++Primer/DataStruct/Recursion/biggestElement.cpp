#include <iostream>
#include <string>
#include <vector>

using namespace std;

int max(int arr[], int low, int high)
{
    int a, b;
    int mid;
    if(low == high){
        return arr[low];
    }
    mid = (low + high) / 2;
    a = max(arr, low, mid);
    b = max(arr, mid + 1, high);
    
    return a > b ? a : b;
}

int maxNum(int arr[], int n)
{
    if(n == 0){
        cerr << "Error number" << endl;
        return -65535;
    }
    if(n == 1){
        return arr[0];
    }
    
    int array[n - 1];
    for(int i = 1; i != n; i ++){
        array[i - 1] = arr[i];
    }
    
    return arr[0] > max(array, 0, n - 2) ? arr[0] : max(array, 0, n - 2);
}


int main(int argc, const char *argv[])
{
    int arr[] = {12, 23, 1, 32, 12 , 4, 5, 9};
  
    cout << maxNum(arr, sizeof(arr)/sizeof(int)) << endl;
    cout << maxNum(arr, 1) << endl;
    cout << maxNum(arr, 3) << endl;
    cout << maxNum(arr, 0) << endl;
    return 0;
}
