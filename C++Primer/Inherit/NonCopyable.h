#ifndef __NON_COPYABLE__
#define __NON_COPYABLE__

class NonCopyable{
    private:
        NonCopyable(const NonCopyable &);
        NonCopyable &operator = (const NonCopyable &);
    public:
        NonCopyable(){};
        ~NonCopyable(){};
}

#endif  /*__NON_COPYABLE__*/
