#include <iostream>
#include <string>
#include <vector>
using namespace std;

//将一个指向Base的指针，运行时强制转换成指向Derived指针
//
//如果实际运行中basePtr实际指向的对象是Derived对象，那我们的转换是成功的
//否则转换的结果是0，因为我们这里是指针转换
//
//如果是引用转换失败的时候，那么结果是bad_cast类型的异常
//
//带有虚函数的类RTTI是在运行时确定
//不带虚函数的累RTTI是在编译的时候确定
if(Derived *derivedPtr = dynamic_cast<Derived *>(basePtr)){
    //这里是我们RTTI转换成功的时候执行的代码
}else{
    //这里是RTTI失败的时候执行的代码
}

int main(int argc, const char *argv[])
{
    
    return 0;
}
