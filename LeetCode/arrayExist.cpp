#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int SIZE = 100;

string searchNum(int a[][SIZE], int m, int n, int num)
{
    for(int i = 0; i != m; i ++){
        for(int j = 0; j != n; j ++){
            if(a[i][j] == num){
                return "Yes";
            }
        }
    }
    return "No";
}


int main(int argc, const char *argv[])
{
    cout << "Please input row, column and the number you search : ";
    int m, n, num;
    cin >> m >> n >> num;
    int arr[SIZE][SIZE] = {};
    for(int i = 0; i != m; i ++){
        for(int j = 0; j != m; j ++){
            cin >> arr[i][j];
        }
    }
    
    cout << searchNum(arr, m, n, num) << endl;
    return 0;
}
