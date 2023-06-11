//
// Created by mrpour on 2023/5/4.
//
#include "iostream"

using namespace std;
int Test(){}
int main()
{
    //1、const_cast
    const int a = 100;
    //消除const限制转换
    int* b = const_cast<int*>(&a);
    *b = 200;
    cout<< a <<endl;
    cout<< b <<endl;

    //2、reinterpret_cast:任意转换（很危险），需要前后类型所占的内存大小一致
    //定义函数指针，入参void，返回值void
    typedef void(*Func)();
    //类型不同
    //Func f = &Test;
    //强制类型转换
    Func f = reinterpret_cast<Func> (&Test);

    //3、static_cast:基本类型、类与指针之间的转换，不做检查
    //4、dynamic_cast:只用于含有虚函数的类上下级之间的转化，如果是上向下转，对于非法的结果返回NULL


}