#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//键树，又叫字典树，是一颗度大于等于2的树，树中每一个节点
//不是包含一个或者几个关键字，而是只含有组成关键字的符号

/*
 * Trie思想是利用字符串公共前缀来降低时空开销
 * Trie典型应用是统计和排序大量的字符串。经常用于搜索引擎的文本词频统计
 * Trie的优点是最大限度的减少无谓字符串的比较
 * Trie的缺点是如果大量的字符串且这些字符串没有公共前缀的时候，Trie树是非常消耗内存的
 */

//键树存储方式一：双链树，孩子-兄弟链表
struct doubleNode{
    char c;
    doubleNode *next;
    doubleNode *son;
};

const int branchNum = 26;       //26个字母

//键树存储方式二：多重链表表示，trie树，字典树
struct trieNode{
    bool isStr;                     //判断此处是否是一个字符串
    trieNode *next[branchNum];      //指向各个子树的指针
    
    trieNode()
        :isStr(false)
    {
        memset(next, NULL, sizeof(next));
    }
};

class Trie{
    public:
        Trie(){
            root = new trieNode();
        }
        
        void insert(const char *word);
        bool search(const char *word);
        void deleteTrie(trieNode *root);
        trieNode *getTrie{
            return root;
        }


    private:
        trieNode *root;
};

void Trie::insert(const char *word)
{
    trieNode *local = root;
    while(*word ++){       //如果字母存在，那么我们往下找，否则的话我们添加
        if(local -> next[*word - 'a'] == NULL){     //不存在，则加入
            local -> next[*word - 'a'] = *word;
        }
        local = local -> next[*word - 'a'];
    }
    local -> isStr = true;
}

//再Trie树上面的查找过程：从跟节点出发，沿着给定的值相应指针逐层向下
//如果到达给定值的尾部，并且此时标记为true，则成功
//如果节点中和给定值对应指针为空，或者到达尾部的时候节点标记为false则不成功
bool Trie::search(const char *word)
{
    trieNode *local = root;
    while(*word ++){
        if(local -> next[*word - 'a'] == NULL){
            return false;
        }
        if(local -> isStr == true && local -> next == NULL){
            return true;
        }
        local = local -> next;
    }
    return false;
}

void Trie::deleteTrie(trieNode *root)
{
    for(int i = 0; i != branchNum; i ++)
    {
        if(root -> next[i] != NULL){
            deleteTrie();
        }
    }
    delete root;
}
