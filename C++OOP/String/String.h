#ifndef __STR_ING__
#define __STR_ING__ 

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

class String{
    public:
        String();
        String(const char *);
        String(const char c);
        String(const String &);
        ~String();

        String &operator = (const char *);
        String &operator = (const char c);
        String &operator = (const String &);

        int strSize() const;
    
        //String operator () (unsigned posn, unsigned len) const;           //返回长度为len的子串
        //char operator() (unsigned n) const;                               //返回下标为n的字符
        //const char operator [] (unsigned n) const;                        //返回对下标n的引用
        const char * c_str() const{ return str_;}                         //返回指向内部数据的指针
        

        String &operator += (const String &);
        
        //String &toUpper();
        //String &toLower();
        
    private:
        char *str_;
        int len_;
};
ostream &operator << (ostream &out, const String &);
//istream &operator >> (istream &in,  const Stringg &);
/*
String operator + (const String &, const String &);

bool operator == (const String &, const String &);
bool operator != (const String &, const String &);
bool operator >= (const String &, const String &);
bool operator <= (const String &, const String &);
bool operator > (const String &, const String &);
bool operator < (const String &, const String &);
*/
#endif  /*__STR_ING__*/
