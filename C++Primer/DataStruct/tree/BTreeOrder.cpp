#include <iostream>
#include <string>
#include <vector>

using namespace std;


struct BTNode{
    int data;
    BTNode *left;
    BTNode *right;
};

void MidLeftRight(BTNode *tree)     //先序遍历，中左右
{
    cout << tree -> data << " ";    //中
    MidLeftRight(tree -> left);
    MidLeftRight(tree -> right);
}

void MLR(BTNode *tree)
{
    if(tree == NULL){       //确保不是空树，指针是一个有效指针
        return ;
    }
    
    stack<BTNode *tree> s;
    BTNode *curr = tree;
    BTNode *tmp;
    BTNode *r = NULL;
    

    while(curr != NULL){
        if(curr){
            cout << curr -> data << " ";        //输出跟节点的值
            s.push(curr);
            curr = curr -> left;
        }else{          //右子树存在且没有被访问过
            curr = s.pop();
            if(curr -> right && curr -> right != r){
                curr = curr -> right;
                cout << curr -> data << " ";
                s.push(curr);
                curr = curr -> left;
            }
        }
    }
}


void LRM(BTNode *tree)
{
    stact<BTNode *> s;
    BTNode *p = tree;       //我们读到的位置
    BTNode *r = NULL;
    BTNode tmp;

    while(p || !s.empty()){
        if(p){
            s.push(p);
            p = p -> left;
        }else{      //!p也就是说p为NULL，我们要返回上一个节点
            p = s.top();    //这是我们上一个节点
            if(p -> right && p -> right != r){
                p = p -> right;
                s.push(p);
                p = p -> left;
            }else{
                p = s.top();
                s.pop();
                cout << p -> data << " ";
                r = p;
                p = NULL;
            }
        }
    }
}

int main(int argc, const char *argv[])
{
    
    return 0;
}
