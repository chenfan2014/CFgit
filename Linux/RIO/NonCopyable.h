#ifndef __NON_COPYABLE__
#define __NON_COPYABLE__

class NonCopyable{
    public:
        NonCopyable(){};
        ~NonCopyable(){};
    private:
        NonCopyable(const NonCopyable &);
        void operator = (const NonCopyable &);
};

#endif  /*__NON_COPYABLE__*/
