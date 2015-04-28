#include <iostream>
#include <string>
#include <vector>
#include <stddef.h>
#include<string.h>
#include <stdlib.h>
using namespace std;
enum SortOrder{Ascending, 
               Descending};
class ArrayImplementation{
    protected:
        ArrayImplementation(size_t size)
        {
            if(size > 0){
                size_ = size;
                vp_ = new void *[size];         //vp是指向 指针数组的 指针
                 for (int i = 0; i <size_; i++) {
                     vp_[i] = 0;
                 }
            }else{
                size_ = 0;
                vp_ = 0;
            }
        }

        ArrayImplementation(const ArrayImplementation &other)
        {
            if(other.size_ > 0){
                size_ = other.size_;
                vp_ = new void *[size_];
                for (int i = 0; i < size_; i++) {
                    vp_[i] = other.vp_[i];
                }
            }else{
                size_ = 0;
                vp_ = 0;
            }
        }

        ArrayImplementation operator = (const ArrayImplementation &other)
        {
            if(this == &other){
                return *this;
            }
            if(size_ > other.size_){
                for (int i = 0; i < other.size_; i++) {
                    vp_[i] = other.vp_[i];
                }
                size_ = other.size_;
            }else{
                delete [] vp_;
                vp_ = new void *[other.size_];
                size_ = other.size_;
                for (int i = 0; i < other.size_; i++) {
                    vp_[i] = other.vp_[i];
                }
            }
            return *this;
        }
        
        void *Put(size_t index, const void *what)        //index是下表，what是值，这个是赋值操作
        {
            void *oldValue = vp_[index];
            vp_[index] = const_cast<void *>(what);
            return oldValue;
        }
        void *Get(size_t index)
        {
            return vp_[index];
        }

        void Print() const
        {
            for (int i = 0; i < size_; i++) {
                cout << vp_[i] << " " << endl;
            }
        }
        size_t size_;
        void **vp_;                             //指向 指针数组的 指针

};

class NoObjectException{            //this exception point out that the index has no object
    public:
        NoObjectException(size_t index)
            :index_(index)
        {}

        size_t GetFailingIndex() const
        {
            return index_;
        }

        const char *GetDescription() const
        {
            cout << "There is no object at the specificaed index"  << endl;
        }
    private:
        size_t index_;
};


class RangeErrorException{
    public:
        RangeErrorException(size_t index, size_t size)
            :index_(index), size_(size)
        {}

        size_t GetFailingIndex() const
        {
            return index_;
        }
        size_t GetArraySize() const
        {
            return size_;
        }

        const char *GetDescription() const
        {
            return "The specified index is out of range";
        }
    private:
        size_t index_;
        size_t size_;
};

const size_t ARRAYSIZE = 256;
template<class AType>
class SafeArray : private ArrayImplementation{
    SafeArray(int sz = ARRAYSIZE)
        :ArrayImplementation(sz)
    {}
    SafeArray(const SafeArray<AType> &other)
        :ArrayImplementation(other)
    {}
    SafeArray<AType> &operator = (const SafeArray<AType> &other)
    {
        ArrayImplementation::operator = (other);
        return *this;
    }
    ~SafeArray(){};

    int GetSize() const
    {
        return size_;
    }
    AType &Get (size_t where)
    {
        if(where >= 0 && where < size_)
        {
            void *p = ArrayImplementation::Get(where);
            if(p != 0){
                return *(reinterpret_cast<AType *>(p));
            }else{
                throw NoObjectException(where);
            }
        }
        else
        {
            throw RangeErrorException(where, size_);
        }
        AType *ap = 0;
        return *(ap);
    }

    AType &Put(size_t where, const AType &what)
    {
        if(where >= 0 && where < size_){
            void *p = ArrayImplementation::Put(where, &what);
            return *(reinterpret_cast<AType *>(p));
        }else{
            throw RangeErrorException(where, size_);
        }
        AType *ap = 0;
        return *(ap);
    }
    AType &operator [] (size_t index)
    {
        return Get(index);
    }
    void Print() const
    {
        for (int i = 0; i < size_; i++) {
            if(vp_[i] != 0){
                cout << *(reinterpret_cast<AType *>(vp_[i])) << " " << endl;
            }
        }
    }
};

int main(int argc, const char *argv[])
{
    
    return 0;
}
