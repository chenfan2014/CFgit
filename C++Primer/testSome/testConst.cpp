#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char *argv[])
{
    int i = 10;

    int &j = i;
    j += 20;
    cout << i << endl;
    
    string sss;
    cout << "s[0] :" << sss[0] << ":"<< endl;
    
    string str("South China");
    string *s = &str;
    string *s1;
    s1 = &str;
    cout << *s << " " << *s1 << endl;
    
    int a = 100;
    int *p1 = &a;
    int *p2 = p1;
    int *p3;
    p3 = p1;
    cout << *p1 << " " << *p2 << " " << *p3 << endl;

    return 0;
}
