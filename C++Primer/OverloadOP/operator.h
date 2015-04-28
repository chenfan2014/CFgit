#ifndef __OPER_ATOR
#define __OPER_ATOR 

#include <iostream>
#include <string>
#include <vector>

Class T{
    public:
        
        T &operator ++(){
            
        }

        T &operator += (const & other){
            ival += other.ival;
            sval += other.ival;
            return *this;
        }
    private:
        int ival;
        string sval;
}


T operator + (const T &lvalue, const T &rvalue){
    T ret(lvalue);
    ret += lvalue;
    return ret;
}

T operator - (const T &lvalue, const T &rvalue){
    T ret(lvalue);
    ret -= lvalue;
    return ret;
}

#endif  /*__OPER_ATOR*/
