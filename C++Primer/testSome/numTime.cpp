#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int calcNum(int arr[], int n)
{
    int half = (n % 2) == 0 ? n / 2 : (n + 1) / 2;  //出现最少次数
    
    map<int, int> imap;
    for(int i = 0; i != n; i ++){
        imap[arr[i]]++;
    }
    for(map<int, int>::iterator it = imap.begin(); it != imap.end(); ++it){
        if(it -> second >= half){
           return it -> first; 
        }
    }
    return 0;
}

int numTime(int arr[], int length)
{
    int num, numCount;
    for(int i = 0; i != length; i ++){
        num = arr[i];
        numCount = 1;
        
    }
}

int main(int argc, const char *argv[])
{
    int arr[] = {1, 2, 3, 3, 3, 3, 3, 3, 4, 4, 4};
    int num = calcNum(arr, 7);
    cout << num << endl;
    return 0;
}
