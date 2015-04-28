#include <iostream>
#include <string>
#include <vector>

using namespace std;

int InsertSort(int a[], int n)
{
    int i, j;
    for(i = 1; i != n; i ++){               //对后面所有的元素进行循环
        if(a[i] < a[i - 1]){                //往前找
            int j = i - 1;                  //记录我们这个需要去插入的位置的值
            int x = a[i];
            a[i] = a[i - 1];                //先往后移动一个位置
            while(x < a[j]){
                a[j + 1] = a[j];
                j --;
            }
            a[j + 1] = x;
        }
    }

    for(i = 0; i != n; i ++){
        cout << a[i] << " ";
    }
    cout << endl;
}
int main(int argc, const char *argv[])
{
    int a [5] = {3, 2, 4, 1, 5};
    InsertSort(a, 5);
    return 0;
}
