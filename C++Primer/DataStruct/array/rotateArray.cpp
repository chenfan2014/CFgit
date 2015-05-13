#include <iostream>
#include <string>
#include <vector>

using namespace std;

void rotate(int arr[][4])
{
    for(int i = 0; i != 4; i ++){
        for(int j = i; j != 4; j ++){
            int tmp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = tmp;
        }
    }

    for(int j = 0; j != 4/2; j ++){
        for(int i = 0; i != 4; i ++){
            int tmp = arr[i][j];
            arr[i][j] = arr[i][3 - j];
            arr[i][3 - j] = tmp;
        }
    }

}

int main(int argc, const char *argv[])
{
    int arr[][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    for(int i = 0; i != 4; i ++){
        for(int j = 0; j != 4; j ++){
            cout << arr[i][j] << "   ";
        }
        cout << endl;
    }
    rotate(arr);
    cout << "After rotate" << endl;
    for(int i = 0; i != 4; i ++){
        for(int j = 0; j != 4; j ++){
            cout << arr[i][j] << "   ";
        }
        cout << endl;
    }

    return 0;
}
