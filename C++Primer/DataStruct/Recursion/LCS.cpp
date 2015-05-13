#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * 动态规划：空间换取时间
 *
 * 动态规划适用于经过分解得到的子问题不是互相独立的问题
 * 动态规划的四个步骤：
 * 第一：描述最优解的结构       
 * 第二：递归定义最优解的值
 * 第三：按照自底向上的方式求解最优解的值
 * 第四：计算构造出一个最优解
 * 1-3是动态规划的基础。描述结构->定义值->自底向上求解
 * 
 * 适合动态规划的最优化问题的两个关键：最优子结构以及重复子问题
 * 最优子结构：如果问题的最优解包含的子问题的最优解也是最优的，那么这个问题具有最优子结构，当一个问题具有最优子结构的时候
 *             说明我们的动态规划算法可能使用
 * 重复子问题：子问题重复性质是指递归算法自顶向下对问题进行求解的时候，每次产生的子问题并不总是新的问题，有些子问题可能会
 *             被计算多次，动态规划正式利用了子问题的这种性质，对于每一个子问题只计算一次，然后保存计算结果，当我们需要的
 *             时候去取出结果就可以了。从而得到较高的效率
 *
 */

int LCSLength(string &str1, string &str2)       //时间复杂度为O(MN),其中M为str1长度，N为str2的长度
{
    if(str1 < str2){
        swap(str1, str2);
    }
    if(str2.size() == 0){
        return 0;
    }

    int len = 0;
    string tmpStr1, tmpStr2;
    if(str1[0] == str2[0]){
        cout << str1[0];
        len ++;
        tmpStr1 = str1.substr(1);
        tmpStr2 = str2.substr(1);
        len = len + LCSLength(tmpStr1, tmpStr2);
    }else if(str1[0] != str2[0]){
        tmpStr1 = str1.substr(1);
        tmpStr2 = str2.substr(1);
        int len1 = LCSLength(str1, tmpStr2);
        int len2 = LCSLength(tmpStr1, str2);
        len = len1 > len2 ? len1 : len2;
    }
    return len;
}

/*
 * 下面这种方法是LCS的一种变形，我们使用一个二维数组用来存储一些信息
 */

int getStr[100][100];
const int maxNumber = 65535;

int LCSMemo(string &x, string &y, int i, int j)
{
    if(getStr[i][j] < maxNumber){
        return getStr(i, j)
    }
    if(i == 0 || j == 0){
        getStr[i][j] = 0;
    }else if(x[i - 1] == y[j - 1]){
        getStr[i][j] = LCSMemo(x, y, i - 1, j - 1) + 1;
    }else{
        int p = LCSMemo(x, y, i, j - 1);
        int q = LCSMemo(x, y, i - 1, j);
        
        getStr[i][j] = p > q ? p : q;
    }
    return getStr[i][j];
}

int LCSLengthSecond(string &str1, string &str2)
{
    memset(getStr, maxNumber, sizeof(GETSTR));
    return LCSMemo(str1, str2, str1.size(), str2.size());
}


int main(int argc, const char *argv[])
{
    string str1, str2;
    string str;
    int len;
    while(1)
    {
        cin >> str1 >> str2;
        len = LCSLength(str1, str2);
        cin.sync();
        cout <<   " : Len is " << len << endl; 
    }
    return 0;
}
