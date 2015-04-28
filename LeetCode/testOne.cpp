#include <iostream>
#include <string>
#include <set>

using namespace std;

int countMax(string s, int x, int y, int z)
{
    set<int> sSet;
    sSet.insert(x);
    sSet.insert(y);
    sSet.insert(z);
    set<int>::iterator it = sSet.begin();   //对三个数进行排序

    int count = 0;
    int Cr = 0, Cy = 0, Cb = 0;
    int countNumber = 0;        //统计总共有多少个求
    int maxNumber = 0;
    int i = 0;
    while(s[i]){
        if(s[i] == 'R'){          
            Cr ++;
        }else if(s[i] == 'Y'){
            Cy ++;
        }else{
            Cb ++;
        }
        countNumber ++;
        cout << Cr << " " << Cy << " " << Cb <<  " " << countNumber << endl; 
        int sr = Cr - Cy > 0 ? Cr - Cy : Cy - Cr;
        int sy = Cy - Cb > 0 ? Cy - Cb : Cb - Cy;
        int sb = Cb - Cr > 0 ? Cb - Cr : Cr - Cb;
        cout << sr << " " << sy << " " << sb << " " << endl;
        set<int> s2;
        s2.insert(sr);
        s2.insert(sy);
        s2.insert(sb);
        set<int>::iterator it2 = s2.begin();
        while(*it2 == *it){
            count ++;
            ++ it;
            ++ it2;
            if(count == 3){
                break;
            }
        }
        if(count == 3 || (i == s.size() - 1)){
            cout << "In this" << endl;
            maxNumber = maxNumber >  countNumber ? maxNumber : countNumber;
            Cr = Cy = Cb = countNumber = 0;
        }
        i ++;
        count = 0;
        it = sSet.begin();
    }
    return maxNumber;
}

int main(int argc, char *argv[])
{
    int x, y, z;
    cin >> x >> y >> z;
    string str;
    cin >> str;
    cout << countMax(str, x, y, z) << endl;
}
