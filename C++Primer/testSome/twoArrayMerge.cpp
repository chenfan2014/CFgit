#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int SIZE = 100;
void mergeArray(int a[], int b[], int m, int n)
{
    if(n == 0){
        return ;
    }
    int k = m + n - 1;
    int i = m - 1;
    int j = n - 1;

    while(i >= 0 && j >= 0)
    {
        if(a[i] > b[j]){    //
            a[k --] = a[i --];
        }else{
            a[k --] = b[j --];
        }
    }
}

int main(int argc, const char *argv[])
{
    int a[] = {1, 3, 5, 6, 7};
    int b[] = {2, 4, 6};

    int s1 = sizeof(*a)/sizeof(int);
    int s2 = sizeof(b)/sizeof(int);
    

    mergeArray(a, b, s1, s2);
    for(int i = 0; i != s1 + s2; i ++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
