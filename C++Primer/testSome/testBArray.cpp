#include <iostream>
#include <string>
#include <vector>
using namespace std;

void countArrB(int arrB[], int arrA[], int num)
{
    int i, j;
    for(i = 0; i != num; i ++){
        
        for(j = 0; j != num; j ++){
            if(j == i){
            }else{
                arrB[i] = arrB[i] * arrA[j];
            }
        }
    }
}

void printArr(int arr[], int num)
{
    for(int i = 0; i != num; i ++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(int argc, const char *argv[])
{
    int arrA[10] = {1, 2 ,3 ,4, 5, 6, 7, 8, 9, 10};
    int arrB[10] = {1, 1, 1, 1, 1, 1, 1 ,1 ,1 ,1 };
    countArrB(arrB, arrA, 10);
    printArr(arrB, 10);
    return 0;
}
