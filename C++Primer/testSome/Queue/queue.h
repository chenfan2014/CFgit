#ifndef __QUEUE_H__
#define __QUEUE_H__ 

#include <iostream>
#include <string>
#include <vector>

//链表中的节点
template<typename T>
class QueueItem{
    friend class Queue<T>;
    private:
        T item_;
        QueueItem *next_;
        QueueItem(const T &t)
            :item_(t),next_(0)
        {}
};

//队列：每一个元素都可以往前或者是往后，然后其次队列首出，队尾入，先进先出
template <typename T> 
class Queue{
    private:
        QueueItem<T> *head;     //首部元素
        QueueItem<T> *tail;     //尾部元素
        void destroy();         //删除all元素
        void copyElems(const Queue &);      //复制构造函数
    public:
        Queue()                 //空队列
            :head(0), tail(0)
        {}
        Queue(const Queue &q)   
            :head(0), tail(0)
        {
            copyElems(q);
        }

        Queue &operator = (const Queue &);  //赋值操作符
        ~Queue(){
            destroy();
        }

        //返回首节点元素，但是没有对队列是否为空做判断
        T &front(){
            return head -> item;
        }
        const T &front() const{
            return head -> item;
        }

        void push(const T &);               //添加元素
        void pop();                         //删除元素

        bool empty() const{                 //判断队列是否为空
            return head == 0;
        }
};

#endif  /*__QUEUE_H__*/
