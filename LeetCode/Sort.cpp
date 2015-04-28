#include <iostream>
#include <string>
#include <vector>
using namespace std;

int partation(int ivec[], int low, int high)
{
   int val = ivec[low];
   while(low < high){
       while(low < high && ivec[high] >= val){
           high --;
       }
       ivec[low] = ivec[high];
       while(low < high && ivec[low] <= val){
           low ++;
       }
       ivec[high] = ivec[low];
   }
   ivec[low] = val;
   return low;
 
   return 1; 
}

void quickSort(int ivec[], int low, int high)
{
    if(low < high)
    {
        int pos = partation(ivec, low, high);
        quickSort(ivec, low, pos - 1);
        quickSort(ivec, pos + 1, high);
    }
}

int main(int argc, const char *argv[])
{
    int arr[] = {12, 90, 3, 32, 321, 8, 9, };
    int size = sizeof(arr)/sizeof(int);
    quickSort(arr, 0, size - 1);
    for(int i = 0; i != size; i ++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
