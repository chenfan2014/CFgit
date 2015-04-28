#ifndef __OVERLOAD__OP__
#define __OVERLOAD__OP__ 

#include <string>
#include <iostream>

class String{
    private:
        std::string str_;
    public:
        String();                   //构造函数
        String(const std::string &);     //构造函数
        String(const String &);     //复制构造函数
        ~String();                  //析够函数

        String &operator = (const String &);    
        String &operator += (const String &);
        //String &operator >= (const String &, const String &);
        //String &operator <= (const String &，const String &);

};

#endif  /*__OVERLOAD__OP__*/
