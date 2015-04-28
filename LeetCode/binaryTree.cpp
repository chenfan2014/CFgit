#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct binaryTreeNode{
    //结点值，左孩子，右孩子
    int value;
    struct binaryTreeNode *lchild;
    struct binaryTreeNode *rchild;
};

void postOrder(binaryTreeNode *bt)  //先序遍历
{
    stack<binaryTreeNode *> s;      //建立一个栈。用来存放我们的遍历数值
    binaryTreeNode *p = bt, *r = NULL, temp;

    while(p || !s.empty()){         //当树不是空树的时候
        if(p){
            s.push(p);
            p = p -> lchild;        //把P值放入栈中，同时让他指向左孩子
        }else{
            p = s.top();            //取栈顶结点
            if(p -> rchild && p -> rchild != r){    //右子树存在并且没有被访问过
                p = p -< rchild;
                s.push(p);
                p = p -> lchild;
            }else{
                p = s.top();
                s.pop();
                cout << p -> data;
                r = p;
                p = NULL;
            }
        }
    }
}


void postOrder(binaryTreeNode *bt)      //先序遍历
{
    stact<binaryTreeNode *> st;
    binaryTreeNode *p = bt;

    while(p || !s.empty())              //
    {
        if(p){
            s.push();
            p = p -> lchild;            //
        }
    }
}

int main(int argc, const char *argv[])
{
    
    return 0;
}
