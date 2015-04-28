include "queue.h"


template<typename T>
void Queue<T>::destroy(){
    while(!empty){
        pop();
    }
}

template<typename T>
void Queue<T>::pop(){
    QueueItem<T> *p = head;
    head = head -> next;
    delete p;
}

template<typename T>
void Queue<T>::push(const T &tval){
    QueueItem<T> *pt = new QueueItem<T>(tval);
    if(empty()){
        head = tail = pt;
    }else{
        tail -> next = pt;
        tail = pt;
    }
}

template<typename T>
Queue<T> &Queue::operator = (const Queue<T> & qval){
    destroy();
    for(QueueItem<T> *pt = qval.head; pt != tail; pt = pt -> next){
        push(pt -> item);
    }
    return *this;
}

template<typename T>
void Queue<T>::copyElems(const Queue<T> &qval){
    for(QueueItem<T> *pt = qval.head; pt != tail; pt = pt -> next){
        push(pt -> item);
    }
}
