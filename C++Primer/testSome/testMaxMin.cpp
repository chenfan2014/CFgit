#include <iostream>
#include <string>
#include <vector>
using namespace std;

void searchMaxAndMin(int arr[],int n, int &max, int &min)
{
    cout << "Go in" << endl;
    if(n % 2 == 0){
        for(int i = 0; i != n - 2; i += 2){
            if(arr[i] > arr[i + 1]){
                if(arr[i] > max){
                    max = arr[i];
                }
                if(arr[i + 1] < min){
                    min = arr[i + 1];
                }
            }else{
                if(arr[i + 1] > max){
                    max = arr[i + 1];
                }
                if(arr[i] < min){
                    min = arr[i];
                }
            }
        }
    }else{
        for(int i = 0; i != n - 2; i += 2){
            if(arr[i] > arr[i + 1]){
                if(arr[i] > max){
                    max = arr[i];
                }
                if(arr[i + 1] < min){
                    min = arr[i + 1];
                }
            }else{
                if(arr[i + 1] > max){
                    max = arr[i + 1];
                }
                if(arr[i] < min){
                    min = arr[i];
                }
            }
        }
        
    }
}

int main(int argc, const char *argv[])
{
    int arr[] = {100, 23, 32, 213, 321, 12354, 54, 3, 3322, 12, 1, 432};
    int max = arr[1];
    int min = arr[1];
    searchMaxAndMin(arr, 12, max, min);
    cout << max << endl;
    cout << min << endl;
    return 0;
}
