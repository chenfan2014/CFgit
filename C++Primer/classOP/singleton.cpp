#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <pthread.h>
using namespace std;
class Singleton{
    public:
        static Singleton *getInstance(){   //这里是我们在类内部的成员函数，用来生成类对象
            lock_.lock()
            if(pInstance == NULL){
                sleep(2);
                Singleton *pInstance = new Singleton;
            }
            return *pInstance;
        }
    private:
        Singleton(){};      //构造函数设为私有，这样外部就无法生成对象

        Singleton(const Singleton &);
        Singleton &operator = (const Singleton &);
        //上面两句是禁用复制和赋值操作

        static Singleton *pInstance_;
}

Singleton *Singleton::pInstance_ = NULL;

void *threadFunc(void *arg){
    Singleton *p = Singleton::getInstance();
    cout << p << endl;
    return NULL;
}
int main(int argc, const char *argv[])
{
    vector<pthread_t> vec(50);
    for(auto &it : vec){
        pthread_create(&it, NULL, threadFunc, NULL);
    }
    for(auto &it : vec){
        pthread_join(it, NULL);
    }
    return 0;
}
