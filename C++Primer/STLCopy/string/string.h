#ifndef __STRING_C__
#define __STRING_C__ 

#include <iostream>
#include <string>

namespace str_{
    class String{
        private:
            char *str_;
        public:
            String();
            ~String();
            String(const char *);
            String(const String &);
            void print();
            std::size_t size() const;
    };
}
#endif  /*__STRING_C__*/
