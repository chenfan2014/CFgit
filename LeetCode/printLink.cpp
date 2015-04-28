#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct LNode{
    int value;
    struct LNode *next;
};
void print(LNode *node)
{
    while(node){
        cout << node -> value << endl;
        node = node -> next;
    }
}
void rearLinkList()
{
    LNode *head, *last;
    LNode *curr;
    last = new LNode;
    last -> next = NULL;
    
    while(1)
    {
        cin >> data;
        curr -> value = data;
        curr -> next = NULL;
        last -> next = curr -> data;
        last = curr;
    }
}
void HeadLinkList()
{
    LNode *node;
    LNode *curr;
    node = new LNode;
    node -> next = NULL;
    int data;

    while(1)
    {
        cin >> data;
        curr = new LNode;       //初始化一下我们待插入的结点
        curr -> value = data;   //把我们输入的值赋值
        curr -> next = node-> next;    //node 这里指向我们的第一个元素，然后我们把第一个元素往后面移动一个位置
        node -> next = curr;            //把我们当前的元素变成第一个元素
    }
}
int main(int argc, const char *argv[])
{
    LNode *node, *head;
    int data;
    head = new LNode;
    head -> next = NULL;
    
   


    while(1)
    {
        cin >> data;
        if(data == -1){
            break;
        }
        node = new LNode;
        node -> value = data;
        node -> next = head -> next;
        head -> next = node;
    }
    print(head);
    return 0;
}
