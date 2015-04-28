#include "string.h"
#include <string.h>
namespace str_{
    String::String(){
        str_ = new char;
        str_[0] = 0;
    }
    
    String::String(const char *str){
        str_ = new char[strlen(str) + 1];
        strcpy(str_, str);
    }
    
    String::String(const String &Str){
        str_ = new char[strlen(Str.str_) + 1];
        strcpy(str_, Str.str_);
    }

    std::size_t String::size() const{
        return strlen(str_);
    }

    void String::print(){
        std::cout << str_ << std::endl;
    }

    String::~String(){
        delete [] str_;
    }
}
