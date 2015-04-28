#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int MAXSIZE = 100;

void rebuildTree(int pre[], int mid[], int nodeNum)
{
   int tree[MAXSIZE] = {};
}

int main(int argc, const char *argv[])
{
    int preArr[MAXSIZE] = {};
    int midArr[MAXSIZE] = {};
    int backArr[MAXSIZE] = {};
    int nodeNum;
    int numVal;
    int count = 0;
    cout << "Please input Node of the Tree : " ;
    cin >> nodeNum;
    cout << "Plaase input the preOrder : ";
    while(cin >> numVal){
        if(count != nodeNum - 1){
            preArr[count] = numVal;
        }else{
            break;
        }
    }
    count = 0;
    cout << "Plaase input the preOrder : ";
    while(cin >> numVal){
        if(count != nodeNum - 1){
            midArr[count] = numVal;
        }else{
            break;
        }
    }

    rebuildTree(preArr, midArr, nodeNum);
    return 0;
}
