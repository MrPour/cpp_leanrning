//
// Created by mrpour on 2023/3/6.
//

#ifndef C__LEARNING_SINGLETON_H
#define C__LEARNING_SINGLETON_H

#include "stdio.h"
#include "iostream"
using namespace std;
class Singleton {
public:
    //获取实例,返回const Singleton*指针
    //由于可能返回的This为NULL，所以使用指针
    static const Singleton* getInstance();
    //【与java不同】：const指针不能改变对象，因此只能调用const成员/静态成员，否则可能修改对象的属性
    void DoSth() const{cout<<"aaa"<<endl;};

//私有化构造函数和析构函数，防止外部访问
private:
    Singleton();
    ~Singleton();
    //使用静态变量，存在于全局区域--
    // 生命周期：系统共生命周期（不需要考虑堆与栈的分配与释放问题，系统接管）
    // 可见范围：Singleton内部可见
    static Singleton* This;
};


#endif //C__LEARNING_SINGLETON_H
