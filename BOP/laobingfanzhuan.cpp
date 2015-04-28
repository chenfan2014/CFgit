#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;
int main(int argc, const char *argv[])
{
    int num;
    cout << "Please input the number of pancake : ";
    cin >> num;
    vector<int> vec;
    for (int i = 0; i != num; i++) {
        vec.push_back(rand() % 100);
    }
    for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it){
        cout << *it << "  ";    
    }
    cout << endl << endl;
    int count = 0;
    while(count != num){    //意思是这个程序需要执行num - 1次
        int maxNum = vec[0];    //把第一个元素设置为最大值
        int dis = 0;            //记录最大值的位置
        for(size_t ix = 0; ix != num - count; ++ix){
            if(vec[ix] > maxNum){
                maxNum = vec[ix];       //找出最大值，记录下来
                dis = ix;               //记录最大值的位置
            }
        }
        for(size_t ix = 0; ix <= dis / 2; ++ix){    
            //这个循环是为了实现刚刚已经找到的最大值放到队首
            int mid = vec[ix];
            vec[ix] = vec[dis - ix];
            vec[dis - ix ] = mid;
        }
        for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it){
            cout << *it << "  ";    
        }
        cout << endl;
        for(size_t ix = 0; ix <= (num - count - 1) / 2; ++ ix){
            int mid = vec[ix];
            vec[ix] = vec[num - count - ix - 1];
            vec[num - count - ix - 1] = mid;
        }
        for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it){
            cout << *it << "  ";    
        }
        cout << endl << endl;
        count ++;
    }
    return 0;
}
