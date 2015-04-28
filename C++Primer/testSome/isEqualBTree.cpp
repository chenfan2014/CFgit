#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<typename T>
class BTNode{
    friend bool isEqual();
    private:
        T value;
        BTNode *lchild;
        BTNode *rchild;

    public:
        BTNode()
            :lchild(NULL), rchild(NULL)
        {}

        BTNode(const T &value)
            :value(value), lchild(NULL), rchild(NULL)
        {}
};

template<typename T>
bool isEqual(BTNode<T> *bt1, BTNode<T> *bt2)
{
    if(bt1 == NULL && bt2 == NULL){
        return 1;
    }
    if(!bt1 || !bt2){
        return 0;
    }

    if(bt1 -> value == bt2 -> value){
        return isEqual(bt1 -> lchild, bt2 -> lchild) && isEqual(bt1 -> rchild, bt2 -> rchild);
    }else{
        return 0;
    }
}

template<typename T>
bool isRotateEqual(BTNode<T> *bt1, BTNode *bt2)
{
    if(bt1 == NULL && bt2 == NULL){
        return 1;
    }
    if(!bt1 || !bt2){
        return 0;
    }
    if(bt1 -> value == bt2 -> value){
        return isEqual(bt1 -> lchild, bt2 -> rchild) && isEqual(bt1 -> rchild, bt2 -> rchild) && isEqual(bt1 -> lchild, bt2 -> rchild) && isEqual(bt1 -> rchild, bt2 -> lchild);
    }
}

template<typename T>
int treeHeight(BTNode<T> *root)
{
    int left, right;
    if(root == NULL){
        return -1;
    }else{
        left = treeHeight(root -> lchild);
        right = treeHeignt(root -> rchild);
        return left > right ? left : right;
    }
}

int main(int argc, const char *argv[])
{
    
    return 0;
}
