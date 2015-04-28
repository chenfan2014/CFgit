#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int findMidSortArr(int a[], int b[], int na, int nb)
{
    int arr[na + nb];
    for(int i = 0; i != na; i ++)
    {
        arr[i] = a[i];
    }
    for(int j = 0; j != nb; j ++)
    {
        arr[na + j] = b[j];
    }
    
    sort(arr, arr + na + nb);
     for(int i = 0; i < na + nb; i++) {
         cout << arr[i] << " ";
     }
     cout << endl;
    return arr[(na + nb)/2];
}

int main(int argc, const char *argv[])
{
    int a[] = {12, 14, 16, 18};
    int b[] = {7, 9, 13, 15, 17, 19};
    cout << findMidSortArr(a, b, 4, 6) << endl;
    return 0;
}
