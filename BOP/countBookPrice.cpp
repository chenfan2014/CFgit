#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
#define MAXMONEY 100000
template <typename T> 
void ChooseSort(T a[5])             //插入排序
{
    for(int i = 0; i != 5; i ++)    //把每一个a[i]当成是max值
    {   
        for(int j = i + 1; j != 5; j ++)
        {
            if(a[j] > a[i])
            {
                T mid = a[i];
                a[i] = a[j];
                a[j] = mid;
            }
        }
    }       //到此为止排好序
}
double minOnce(double m1, double m2, double m3, double m4, double m5)
{
    //这里是计算我们每次递归的最小价格
    double min[5] = {m1, m2, m3, m4, m5};
    ChooseSort(min);
    return min[4]; 
}

double minMoney(int x1, int x2, int x3, int x4, int x5)//动态规划递归实现
{
    int sort[5] = {x1, x2, x3, x4, x5};
    ChooseSort(sort);
    x1 = sort[0];
    x2 = sort[1];
    x3 = sort[2];
    x4 = sort[3];
    x5 = sort[4];
    if(sort[4] > 0){
        return minOnce( (8*5*0.75 + minMoney(x1-1, x2-1, x3-1, x4-1, x5-1)), 
                        (8*4*0.8 + minMoney(x1-1, x2-1, x3-1, x4-1, x5)),
                        (8*3*0.9 + minMoney(x1-1, x2-1, x3-1, x4, x5)),
                        (8*2*0.95 + minMoney(x1-1, x2-1, x3, x4, x5)),
                        (8 + minMoney(x1-1, x2, x3, x4, x5))
                        );
    }else if((sort[4] == 0) && (sort[3] > 0)){
        return minOnce( (8*4*0.8 + minMoney(x1-1, x2-1, x3-1, x4-1, x5)),
                        (8*3*0.9 + minMoney(x1-1, x2-1, x3-1, x4, x5)),
                        (8*2*0.95 + minMoney(x1-1, x2-1, x3, x4, x5)),
                        (8 + minMoney(x1-1, x2, x3, x4, x5)),
                        MAXMONEY
                        );
        
    }else if((sort[3] == 0) && (sort[4] == 0) && (sort[2] > 0)){
        return minOnce( (8*3*0.9 + minMoney(x1-1, x2-1, x3-1, x4, x5)),
                        (8*2*0.95 + minMoney(x1-1, x2-1, x3, x4, x5)),
                        (8 + minMoney(x1-1, x2, x3, x4, x5)),
                        MAXMONEY,
                        MAXMONEY
                        );
        
    }else if((sort[4] == 0) && (sort[3] == 0) && (sort[2] == 0) && (sort[1] > 0)){
        return minOnce( (8*2*0.95 + minMoney(x1-1, x2-1, x3, x4, x5)),
                        (8 + minMoney(x1-1, x2, x3, x4, x5)),
                        MAXMONEY,
                        MAXMONEY,
                        MAXMONEY
                        );
    }else if((sort[4] == 0) && (sort[3] == 0) && (sort[2] == 0) && (sort[1] == 0) && (sort[0] > 0)){
        return minOnce( (8 + minMoney(x1-1, x2, x3, x4, x5)),
                        MAXMONEY,
                        MAXMONEY,
                        MAXMONEY,
                        MAXMONEY
                        );
    }else{
        return 0;
    }
}



int main(int argc, const char *argv[])
{
    int arr[5] = {0};
    cout << "Please input the books of A : ";
    cin >> arr[0];
    cout << "Please input the books of B : ";
    cin >> arr[1];
    cout << "Please input the books of C : ";
    cin >> arr[2];
    cout << "Please input the books of D : ";
    cin >> arr[3];
    cout << "Please input the books of E : ";
    cin >> arr[4];
    double totalMoney = minMoney(arr[0], arr[1], arr[2], arr[3], arr[4]);
    cout << "Total Min Money : " << totalMoney << endl;
    return 0;
}


