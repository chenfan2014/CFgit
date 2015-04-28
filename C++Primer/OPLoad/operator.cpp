#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include "operator.h"
using namespace std;

String::String()
    :str_(" ")
{}

String::String(const string &str)
    :str_(str)
{}

String::~String(){
}

String::String(const String &s){
    str_ = s.str_;
}

String &String::operator = (const String &s){
    if(this != &s){
        strcpy(str_, s.str_.c_str());
        //str_ = s.str_;
    }
    return *this;
}

String &String::operator += (const String &s){
    
}
