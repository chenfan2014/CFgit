#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<typename T>
class BTNode{
    friend class BinaryTree;
    private:
        T data;
        BTNode *lchild;
        BTNode *rchild;
    public:
        BTNode()
            :lchild(NULL), rchild(NULL)
        {}

        BTNode(const T &val)
            :data(val), lchild(NULL), rchild(NULL)
        {}
};

template<typename>
class BinaryTree{
    private:
        BTNode<T> *root;        //一棵空树
    public:
        BinaryTree()
            :root(NULL)
        {}

        BTNode *getRoot() const{
            return root;
        }

        T addNode(const T &value);
}

template<typename T>
T BinaryTree<T>::addNode(const T &value)
{
    if(root == NULL){   //根节点为NULL，空树
        root = new BTNode<T>(value);
    }else{
        //获取根节点
        BTNode<T> *node = root;
        while(1){
            if(value > node -> data){   //值大，我们放在右子树上面
                if(node -> rchild == NULL){
                    node -> rchild = new BTNode<T>(value);
                }else{
                    node = node -> rchild;
                }
            }
            if(value < node -> data){
                if(node -> lchild == NULL){
                    node -> lchild = new BTNode<T>(value);
                }else{
                    node = node -> lchild;
                }

            }
        }
    }
    return value;
}

int main(int argc, const char *argv[])
{
    
    return 0;
}
