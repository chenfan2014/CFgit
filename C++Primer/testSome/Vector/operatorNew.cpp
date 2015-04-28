#include <iostream>
#include <string>
#include <vector>
using namespace std;

void *operator new (size_t);
void *operator new [] (size_t);
void *operator delete(void *);
void *operator delete [] (void *);

int main(int argc, const char *argv[])
{
    T *newElement = alloc.allocate(newCapacity);
    T *newElement = static_cast<T*>(operator new [](newCapacity * sizeof(T)));

    alloc.deallocate(elements, end - elements);
    operator delete [] (elements);


    T *newElement = static_cast<T*>(operator new [](newCapacity * sizeof(T)));
    return 0;
}
