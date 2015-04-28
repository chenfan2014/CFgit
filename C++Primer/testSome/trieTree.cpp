#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <string.h>
using namespace std;

const int NUMBER = 26;          //因为26字母，故设为26

/* 在结点中不设数据域，每隔分支结点表示的字符均由其双亲节点中的指针位置所决定 */

struct trieNode{
    bool isStr;                 //记录此处是否构成一个字符串
    trieNode *next[NUMBER];     //指向各个子树的指针

    trieNode()
        :isStr(false)
    {
        memset(next, NULL, sizeof(next));
    }
};

class Trie{
    public:
        Trie()
        {
            root = new trieNode();
        }

        void insert(const char *);
        bool search(const char *);
        void deleteTrie(trieNode *);

        trieNode *getTrie()
        {
            return root;
        }
    private:
        trieNode *root;

};

void Trie::insert(const char *word)
{
    trieNode *local = root;
    while(*word){
        if(local -> next[*word - 'a'] == NULL){     //不存在则建立一个新的分支结点
            trieNode *tmp = new trieNode();
            local -> next[*word - 'a'] = tmp;
        }

        //这一步我们已经找到了这个点。不管是新建还是已经存在
        local = local -> next[*word - 'a'];

        //每插入一步，相当于有一个新串经过，指针要往下移动
        word ++;
    }
    local -> isStr = true;      //当我们插入完毕的时候，我们把这个isStr标识设置为True，表示是一个字符串
}

/* 
 * 在Trie树查找过程：
 * 从根节点出发，沿和给定值相应的指针逐层向下，若到达给定值的尾部，且此结点为True，则成功
 * 如果节点中和给定值对应的指针为空，或者到达 给定值尾部的时候isStr为false，那么则查找失败
 */
bool Trie::search(const char *word)
{
    trieNode *local = root;
    while(*word && local)
    {
        local = local -> next[*word - 'a'];
        word ++;
    }
    return (local != NULL && local -> isStr);
}

//销毁Trie树
void Trie::deleteTrie(trieNode *root)
{
    for(int i = 0; i != NUMBER; i ++)
    {
        if(root -> next[i] != NULL)
        {
            deleteTrie(root -> next[i]);
        }
    }
    delete root;
}

int main(int argc, const char *argv[])
{
    
    return 0;
}
