#ifndef VECTOR_H
#define VECTOR_H 

template<typename T>
class Vector{
    public:
        Vector()
            :elements(0),
            firstFree(0),
            end(0)
        {}

        void push_back(const T&);
    private:
        static std::allocator<T> alloc;
        void reallocate();
        T *elements;                                //数组第一个元素
        T *firstFree;                               //最后一个实际元素（就是我们存储的元素）的下一个元素，size()
        T *end;                                     //数组本身之后的哪个元素,capacity()
};

template<typename T>
void Vector<T>::push_back(const T &t){
    if(firstFree == end){
        reallocate();                               //判断是否有可用空间，没有使用reallocate函数分配新空间并且复制元素
    }       
    alloc.construct(firstFree, t);                  //初始化对象
    ++firstFree;                                    //实际元素+1
}

template<typename T>
void Vector<T>::reallocate(){
    std::ptrdiff_t size = firstFree - elements;
    std::ptrdiff_t newCapacity = 2 * max(size, 1);

    T *newElemenet = alloc.allocate(newCapacity);

    uninitialized_copy(elements, firstFree, newElemenet);

    for(T *p = firstFree; p != elements; ){
        alloc.destroy(--p);
    }

    if(elements){
        alloc.deallocate(elements, end - elements);
    }

    elements = newElemenet;
    firstFree = elements + size;
    end = elements + newCapacity;
}

template<typename T>
void Vector<T>::reserve(const size_t capa){
    size_t size = firstFree - elements;

    T *Reserve = alloc.allocate(capa);
    if(size <= capa){
        uninitialized_copy(elements, firstFree, Reserve);
    }else{
        uninitialized_copy(elements, elements + capa, Reserve);
    }

    for(T *p = firstFree; p != elements; ){
        alloc.destroy(--p);
    }

    elements = Reserve;
    firstFree = elements + min(size, capa);
    end = elements + capa;
}

template<typename T>
void Vector<T>::resize(const size_t sizeNew){
    size_t size = firstFree - elements;
    size_t capacity = end - elements;
    T *newElemnets = alloc.allocate(sizeNew);
    if(sizeNew > capacity){
        reallocate();
        uninitialized_fill(elements + size, elements + sizeNew, t);
    }else if(newSize > size){
        uninitialized_fill(elements + size, elements + sizeNew, t); 
    }else{
        for(T *p = firstFree; p != elements + sizeNew; ){
            alloc.destroy(--p);
        }
    }

    firstFree = elements + sizeNew;
}

#endif  /*VECTOR_H*/
