#include <iostream>
#include <string>
#include <vector>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct LNode{
    int val;
    LNode *next;
};

void printLink(LNode *link)
{
    //link = link -> next;
    while(link){
        cout << link -> val << " ";
        link = link -> next;
    }
    cout << endl << "End" << endl;
}

LNode *headLink(LNode *head)
{
    //头插法就是每一次插在我们的head前面，我们这里head指向的头结点
    //LNode *head;
    LNode *curr;
    int data;
    int count = 0;

    head = new LNode;       //对head进行初始化
    head -> next = NULL;
    while(cin >> data)
    {
        count ++;
        if(count == 1){
            head -> val = data;
            continue;
        }
        if(data == -1){
            break;
        }
        curr = new LNode;
        curr -> val = data;     //我们赋值给当前结点
        curr -> next = head;    //把我们的头指针指向的结点赋值给我们准备插入的结点
        head = curr;
    }
    return head;
}

LNode *rearLink(LNode *head)
{
    LNode *last;
    //LNode *head;
    LNode *curr;
    int data;
    int count = 0;
    last = new LNode;
    last -> next = NULL;
    head = last;
    while(cin >> data)
    {
        count ++;
        if(count == 1){
            last -> val = data;
            continue;
        }
        if(data == -1){
            break;
        }
        curr = new LNode;
        curr -> val = data;                 //赋值给我们的curr
        curr -> next = last -> next;        //把last指向空赋值给curr
        last -> next = curr;                //然后再把last指向curr
        last = curr;                        //最后把curr赋值为last
    }
    return head;
}
int main(int argc, const char *argv[])
{
    LNode *head;
    head = rearLink(head);
    printLink(head);
    head = headLink(head);
    printLink(head);
    return 0;
}
