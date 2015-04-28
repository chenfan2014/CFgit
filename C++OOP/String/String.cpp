#include "String.h"
using namespace std;

class String;

String::String()
    :str_(0),
    len_(0)
{}

String::String(const char *cstr)      //最后加一表示存放'\0'
{ 
    len_ = strlen(cstr);
    str_ = new char[len_ + 1];
    strcpy(str_, cstr);
}

String::String(const char c)
{
    char *newS = new char [2];
    newS[0] = c;
    newS[1] = '\0';
    len_ = 2;
    str_ = new char[len_];
    strcpy(str_, newS);
}

String::String(const String &other)
    :str_(other.str_),
    len_(other.len_)
{}

String::~String()
{   
    if(str_ != 0){
        delete [] str_;
    }
}

int String::strSize() const{
    return len_;
}

String &String::operator = (const String &other)
{
    if(this != &other){
        this -> str_ = new char [other.len_];
        strcpy(this -> str_, other.str_);
        len_ = other.len_;
    }
    return *this;
}


String &String::operator = (const char *cstr)
{
    if(cstr == 0 && *cstr == 0){
        delete [] str_;
        len_ = 0;
        str_ = 0;
    }else{
        this -> str_ = new char[strlen(cstr) + 1];      //长度不用加上'\0'的长度，但是占用空间
        strcpy(this -> str_, cstr);
        len_ = strlen(cstr);
    }
}

String &String::operator = (const char c)
{
    char s[2];
    s[0] = c;
    s[1] = '\0';
    return (*this = s);
}


String &String::operator += (const String &other)
{
    String midStr(*this);
    len_ = other.strSize() + this -> strSize();
    char *newStr = new char[len_ + 1];
    strcpy(newStr, str_);
    strcat(newStr, other.str_);
    delete [] str_;
    str_ = newStr;

    return *this;
}

ostream &operator << (ostream &out, const String &s)
{
    if(s.c_str()){
        out << s.c_str();
    }
    return out;
}
