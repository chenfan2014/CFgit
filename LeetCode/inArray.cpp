#include <iostream>
#include <stdio.h>
using namespace std;

string search(int a[][1000], int m, int n, int key)
{
    int i = 0;
    int j = n - 1;
    while(i < m && j >= 0)
    {
            if (a[i][j] == key)
                return "Yes";
            else if (a[i][j] < key)
                i++;
            else
                j--;
        }

    return "No";
}

int main()
{
    int n, m;
    int a[1000][1000];
    while(scanf("%d%d", &m, &n) != EOF)
    {
            int key;
            scanf("%d", &key);
            for(int i = 0; i < m; i++)
                for(int j = 0; j < n; j++)
                    scanf("%d", &a[i][j]);
            cout << search(a, m, n, key) << endl;
        }
}
