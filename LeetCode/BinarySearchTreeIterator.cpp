#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct TNode{       
    //搜索二叉树的结点结构
    int val;        //值域
    TNode *left;    //左孩子
    TNode *right;   //右孩子
    TNode(int x)    //初始化结点
        :val(x), left(NULL), right(NULL)
    {}
};

class BSTIterator{
    public:
        BSTIterator(TNode *root){   //迭代器初始化
            while(!stn.empty()){
                stn.pop();
            }

            while(root){
                stn.push(root);         //我们把二叉树的root和左孩子都进行进栈操作
                root = root -> left;
            }
        }

        bool hasNext(){
            return !stn.empty();
        }

        int next(){
           TNode *ret = stn.top();
           stn.pop();

           int retVal = ret -> value;
        }
    private:
        stack<TNode *> stn;
};

int main(int argc, const char *argv[])
{
    TNode *r;
    BSTIterator root(r);
    BSTIterator i = BSTIterator(root);
    while(i.hasNext()){
        cout << i.next() << " ";
    }
    return 0;
}
