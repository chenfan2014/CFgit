#include <iostream>
using namespace std;

int countGold(int x[], int y[], int n)
{
    return 1;
}

int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    int x[n];
    int y[n];
    for(int i = 0; i != n; i ++){
        cin >> x[i] >> y[i];
    }
    
    cout << countGold(x, y, n) << endl;;
}
