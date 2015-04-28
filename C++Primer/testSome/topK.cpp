#include <iostream>
#include <string>
#include <vector>
using namespace std;

int Partation(int arr[], int low, int high)
{
    int ret = arr[low];
    while(low < high){      //快排从后往前,
        while(arr[high] >= ret && low < high){
            high --;
        }

        arr[low] = arr[high];
       

        while(arr[low] < ret && low < high){
            low ++;
        }
        arr[high] = arr[low];
    }
    arr[low] = ret;
    return low;
}

void QuickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int partation = Partation(arr, low, high);
        QuickSort(arr, low, partation - 1);
        QuickSort(arr, partation + 1, high);
    }
}

int *topK(int arr[], int size)
{
    QuickSort(arr, 0, size - 1);
    for(int i = 0; i != size; i ++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return arr;
}


int main(int argc, const char *argv[])
{
    int arr[] = {12, 3, 4, 9, 5, 6, 21, 54, 34, 8};
    int k = 2;
    //cin >> k;
    int *topArr = new int[k];

    topArr = topK(arr, sizeof(arr)/sizeof(int));
    cout << "--------------------" << endl;
    for(int i = 0; i != k; i ++){
        cout << topArr[i] << " ";
    }
    cout << endl;
    return 0;
}
