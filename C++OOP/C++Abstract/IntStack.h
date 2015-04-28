#ifndef __INT_STACK__
#define __INT_STACK__ 

#include <iostream>
#include <string>
#include <vector>

class intStack{
    public:
        intStack();
        intStack(const intStack &);
        intStack operator = (const intStack &);
        ~intStack();

        void push();
        int pop();
        unsigned int howMany() const;

    private:
        int *sp_;
        unsigned count_;
        unsigned size_;
};



#endif  /*__INT_STACK__*/
