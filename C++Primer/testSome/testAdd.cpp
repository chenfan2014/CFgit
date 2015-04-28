#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char *argv[])
{
    int a = 100;
    int b = 100;
    cout << a ++ << endl;       //先返回自身对象，然后再进行加
    cout << ++b << endl;        //返回改变以后的对象，然后在进行加

    cout << a << endl;
    cout << b << endl;

    int c = 5;
    int d = 5;
    int e, f;
    e = (c++) + (c++) + (c++);
    f = (++d) + (++d) + (++d);

    cout << e << " " <<  f << endl;

    int i = 1, j = 2;
    //cout << i+++j++ << endl;
    //cout << ++i+(++j) << endl;
    cout << ++i+j++ << endl;

    double s = 1.23;
    cout << s / 1.2 << endl;

    double t = 1.23;
    t ++;
    cout << t << endl;

    float g = 12.32;
    cout << (g != 23) << endl;

    int x = 0;
    cout << bool(!x) << endl;
    return 0;
}
