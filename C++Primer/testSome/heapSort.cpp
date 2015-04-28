#include <iostream>
#include <string>
#include <vector>

void buildMaxHeap(int arr[], int len)
{
    for(int i = 0; i != len/2; i ++)
    {
        adjustDown(arr, i, len);
    }
}

void adjustDown(int arr[], int k, int len)
{
    arr[0] = arr[k];        //arr[0]暂存元素
    for(int i = 2 * k; i <= len; i *= 2)
    {
        if(i < len && arr[i] < arr[i + 1])
        {
            i ++;
        }
        if(arr[0] > arr[i]){
            break;
        }else{
            arr[k] = arr[i];
            k = i;
        }
    }
    arr[k] = arr[0];
}


void HeapSort(int arr[], int len)
{
    buildMaxHeap(arr, len);
    for(int i = len; i > 1; i --)
    {
        Swap(arr[i], arr[1]);
        adjustDown(arr, 1, i - 1);
    }
}

void adjustUp(int arr[], int k)
{
    arr[0] = arr[k];
    int i = k/2;
    while(i > 0 && arr[i] < arr[0])
    {
        arr[k] = arr[i];
        k = i;
        i = k / 2;
    }

    arr[k] = arr[0];
}
int main(int argc, const char *argv[])
{
    
    return 0;
}
