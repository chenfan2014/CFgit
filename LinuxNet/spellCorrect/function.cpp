#include "header.h"
using namespace std;


int minSize(int a, int b, int c)
{
    int min = a;
    if(min > b){
        min = b;
    }
    if(min > c){
        min = c;
    }
    return min;
}

int editDistance(string s1, string s2, int i, int j)
{
    if(i == 0){
        return j;
    }
    if(j == 0){
        return i;
    }
    if(s1[i] == s2[j]){
        return editDistance(s1, s2, i - 1,j - 1);
    }else{
        //改，s1增，s2增
        return minSize(editDistance(s1, s2, i - 1, j - 1) + 1, editDistance(s1, s2, i, j - 1) + 1, editDistance(s1, s2, i - 1, j) + 1);
    }
}
