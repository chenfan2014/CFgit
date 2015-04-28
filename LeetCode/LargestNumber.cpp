#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

/*
 * 这里我们需要找到一个方法，这里每一个数字都是int类型，我们首先需要对他们所有元素的最高位进行比较
 * 高位比较完了再比较低位。一直到最后一位
 * 可以换一下思路，要想比较两个数在最终结果中的先后位置，何不直接比较一下不同组合的结果大小
 * 举个例子：要比较3和34的先后位置，可以比较334和343的大小，而343比334大，所以34应当在前。
 * 这样，有了比较两个数的方法，就可以对整个数组进行排序。然后再把排好序的数拼接在一起就好了。
 */

int compare(int a, int b)       //这个我们可以用来比较，然后进行排序
{
    int ab = a;     
    int ba = b;
    int ra = a;
    int rb = b;
    while(ra >= 10){
        ba *= 10;
        ra /= 10;
    }
    if(ra <= 9){
        ba = ba * 10 + a;
    }
    
    while(rb >= 10){
        ab *= 10;
        rb /= 10;
    }
    if(rb <= 9){
        ab = ab * 10 + b;
    }
    return ab > ba ? 1 : 0;     //1代表a大，0 代表a小
}

int partation(int ivec[], int low, int high)                                                                                 
{
   int val = ivec[low];
   while(low < high){
       while(low < high && (compare(val, ivec[high])) == 1){      //ret < a[end]
       //while(low < high && ivec[high] >= val){
           high --; 
       }   
       ivec[low] = ivec[high];
       while(low < high && (compare(val, ivec[low])) == 0){      //ret > a[begin]
       //while(low < high && ivec[low] <= val){
           low ++; 
       }   
       ivec[high] = ivec[low];
   }   
   ivec[low] = val;
   return low;
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

string largestNumber(vector<int> &num)
{
    string retStr;
    int size = num.size();
    int arr[size];
    if(num.size() == 0){
        return NULL;
    }else if(num.size() == 1){
        stringstream s;
        s << num[0];
        string s1 = s.str();
        cout << s1 << endl;
        return s1;
    }else{
        int size = num.size();
        int i = 0;
        for(vector<int>::iterator it = num.begin(); it != num.end(); ++it){
            arr[i] = *it;
            i ++;
        }
        quickSort(arr, 0, size - 1);      //这里我们三个参数，数组，起始位置和结束位置
        stringstream s[size];           //数字转变成字符
        string str[size];
        for(int i = 0; i != size; i ++){
            s[i] << arr[i];
            str[i] = s[i].str();
            retStr += str[i];
        }
    }
    return retStr;
}


int main(int argc, const char *argv[])
{
    int a, b;
    vector<int> ivec;
    ivec.push_back(10);
    ivec.push_back(9);
    ivec.push_back(23);
    ivec.push_back(65);
    ivec.push_back(56);
    string s = largestNumber(ivec);
    cout << s << endl;
    return 0;
}
