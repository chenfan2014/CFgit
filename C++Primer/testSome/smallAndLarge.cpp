#include <iostream>
#include <string>
#include <vector>
using namespace std;

void smallAndLarge(int a[], int res[],int n)
{
    int k = 0;
    int i, j;
    for(i = 0; i != n; i ++)
    {
        int flag = 0;
        int max, min;
        max = min = a[i];
        for(j = 0; j != i; j ++){
            if(a[j] > max){
                flag = 1;
            }
        }
        for(j = i + 1; j != n; j ++){
            if(a[j] < min){
                flag = 1;
            }
        }
        if(flag == 0){
            res[k ++] = a[i];
        }
    }   
}

int main(int argc, const char *argv[])
{
    int arr[] = {7, 10, 2, 6, 19, 22, 21};
    int *res = new int[7];
    smallAndLarge(arr, res, 7);
    while((*res) != NULL){
        cout << *res << endl;
        res ++;
    }
    return 0;
}
