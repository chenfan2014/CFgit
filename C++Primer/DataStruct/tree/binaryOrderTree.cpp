#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct BTNode{
    int data;
    BTNode *lchild;
    BTNode *rchild;
};

int judgeOrderTree(BTNode *node)
{
    int b1, b2;
    int prev1 = -65535;
    if(node == NULL){   //判断指针是否有效
        return 1;
    }else{              //指针有效
        b1 = judgeOrderTree(node -> lchild);
        
        if(b1 == 0 || prev1 > node -> data){
            return 0;
        }
        prev1 = node -> data;
        b2 = judgeOrderTree(node -> rchild);
        return b2;
    }
}

int main(int argc, const char *argv[])
{
   
    return 0;
}
