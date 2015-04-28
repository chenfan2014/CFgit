/*
struct LNode{
    ElemType data_;     //信息域，链表数据
    LNode *next_;       //指针域，链表下一个元素位置
};
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Item{
    char c;
    Item *next;
};

Item *RoutineOne(Item *cur)
{
    Item *prev = NULL;
    Item *curr = cur;

    while(curr){                         //当插入的不为空的时候
        Item *next = curr -> next;       //把curr下一个元素传递给next
        curr -> next = prev;             //断开curr和next的关系,让curr指向prev
        prev = curr;                     
        curr = next;                     //把curr放到了prev的位置,然后next变成了curr,头插法
    }
    return prev;
}

void RoutineTwo(Item *list)
{
    Item *curr = list;
    while(curr){
        cout << curr -> c;
        curr = curr -> next;
    }
    cout << endl;
}

int main(int argc, const char *argv[])
{
    Item *x, d = {'d', NULL}, c = {'c', &d}, b = {'b', &c}, a = {'a', &b};
    x = RoutineOne(&a);
    cout << "Begin" << endl;
    RoutineTwo(x);
    return 0;
}

