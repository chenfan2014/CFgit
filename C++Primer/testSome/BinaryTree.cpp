#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<typename T>        //二叉树的结点，把二叉树设为友元类，然后有两个构造函数，一个为空构造函数，一个插入值的时候
class BTNode{
    friend class BTree;
    private:
        T data;
        BTNode *lchild;
        BTNode *rchild;
    public:
        BTNode()
            :lchild(NULL), rchild(NULL)
        {}

        BTNode(const T &value)
            :data(value), lchild(NULL), rchild(NULL)
        {}
};


template<typename T>
class BTree{
    private:
        BTNode<T> *root;
    public:
        BTree()                 //初始化函数
            :root(NULL);
        
        BTNode *getRoot() const{
            return root;        //获取跟结点
        }

        T addValue(const T &value);

        void MLR(const BTree<T> *);    //前序遍历
        void LMR(const BTree<T> *);    //中序遍历
        void LRM(const BTree<T> *);    //后续遍历

};


template<typename T>
T BTree<T>::addValue(const T &value)        //建立一个二叉排序数
{
    if(root == NULL){       //根节点为空，没有数据
        root = new BTNode<T>(value);    //把这个数据插入
    }else{
        BTNode<T> *node = root;     //获取根节点
        while(1){
            if(value > node -> data){   //插入结点>根节点值
                if(node -> rchild == NULL){ //右孩子为空
                    node -> rchild = new BTNode<T>(value);  //把我们的值插入到右结点上面
                }else{
                    node = node -> right;   //往右子树查找插入的位置
                }
            }else{          //这里我们的插入结点<根节点值
                if(node -> lchild == NULL){
                    node -> lchild = new BTNode<T>(value);  //把我们的值插入到左结点上面
                }else{  
                    node = node -> lchild;  //往左子树查找插入位置
                }
            }
        }
    }
    return value;
}


template<typename T>        //递归先序遍历
void BTree<T>::MLR(const BTNode<T> *startNode)
{
    if(startNode == NULL){
        return;
    }else{
        MLR(startNode -> lchild);
        MLR(startNode -> rchild);
        cout << startNode -> data << " ";
    }
}

//根据前序遍历访问的顺序，优先访问根节点，然后分别访问左孩子和右孩子
//即对于任一结点，可以看作是根节点，因此可以直接访问，访问完了之后
//如果其左孩子不为空，按照同样规则访问左子树，当访问左子树的时候
//再访问右子树
//
//对于任一结点P 
//1）访问结点P，并且将P结点入栈
//2）判断结点P的左孩子是否为空，如果为空，则取栈顶结点并且进行出栈操作
//并将栈顶结点的右孩子置位当前结点P。循环至1，如果不为空，
//则将P的左孩子置位当前结点P
//3）直到P为NULL并且栈为空，则遍历结束  

template<typename T>
void BTree<T>::MLR(const BTNode<T> *startNode)  //前序遍历
{
    stack<T *> s;
    BTNode *bt = startNode;
    while(bt!= NULL || !s.empty())
    {
        if(bt){  //如果是P结点
            cout << bt -> data << " ";
            s.push(bt);
            bt = bt -> lchild;
        }else{
            //说明左孩子结点为NULL
            bt = s.top();
            s.pop();
            bt = bt -> rchild;
        }
    }
}

template<typename T>    //中序遍历，左中右
void BTree<T>::LMR(const BTNode<T> *startNode)
{
    if(stackNode == NULL){
        return ;
    }else{
        LMR(stackNode -> lchild);
        cout << stackNode -> data << " ";
        LMR(stackNode -> rchild);
    }
}

/* 
 * 在这里我们进行  左->中->右  遍历，所以我们首先需要进行的是左孩子遍历
 * 当我们遍历到左孩子的时候直接输出结果，然后党我们非左孩子的时候，输出根节点
 * 最后输出右孩子结点
 * 1)如果左孩子不为空，则将P入栈并且将P的左孩子置位当前P，然后对当前结点再进行相同处理
 * 2）如果左孩子为空。则取栈顶元素并且进行出栈操作，访问该栈定点，然后将当前P设置为栈顶点的右孩子
 * 3）知道P为NULL并且栈为空则遍历结束
 */
template<typename T>
void BTree<T>::LMR(const BTNode<T> *startNode)
{
    stack<T *> s;
    BTNode *bt = startNode;
    while(bt != NULL || !s.empty())
    {
        if(bt){
           s.push(bt);
           bt = bt -> lchild;
        }else{
           bt = s.top();
           cout << bt -> data << " ";
           s.pop();
           bt = bt -> rchild;
        }
    }
}


template<typename T>    //后序遍历
void BTree<T>::LRM(const BTNode *startNode)
{
    if(startNode == NULL){
        return ;
    }else{
        LRM(startNode -> lchild);
        LRM(startNode -> rchild);
        cout << startNode -> data << " ";
    }
}


/* 
 * 后序遍历 左->右->中
 * 对于任一一个结点P，将其入栈，然后沿着左子树一直往下搜索，
 * 直到搜索到没有左孩子结点，此时结点出现在栈顶，但是此时不能将其出栈并且访问
 * 因为其右孩子还没有被访问，所以接下来按照相同的规则对其右子树进行相同处理
 * 在这个过程中，每一个结点都出现两次在栈顶，只有当第二次出现在栈顶的时候
 * 才能访问，因此我们需要设置一个变量标识结点是否第一次出现在栈顶
 */
template<typename T>
void BTree<T>::LRM(const BTNode *startNode)
{
    
}

int main(int argc, const char *argv[])
{
    
    return 0;
}
