//
// Created by mrpour on 2023/3/4.
//
#include "stdlib.h"
#include <string.h>
#include "iostream"
using namespace std;
#ifndef C__LEARNING_STRING_H
#define C__LEARNING_STRING_H
class String {
public:
    //1.成员变量只能用指针/变量，不能用引用，数组名本身就可作为指针
    //2.含参构造函数，需要传入一个数组.
    // 无参构造等价于传入NULL，也调用这个函数参数，赋默认值
    String(const char* str = NULL);
    //3.拷贝函数构造
    String(const String& other);
    //4.移动函数构造
    //定义了移动构造函数以后，再调用拷贝构造函数会直接调用移动构造函数

    String(String&& other);
    ~String(void);   //析构函数

    String& operator=(const String& other);
    String& operator=(String&& other) noexcept;
    //【和java不同】：可以在自己类里定义别的类的方法，并访问自己的私有变量
    friend ostream& operator<<(ostream& os,const String& str); //重写ostream的<<操作符
private:
    char* m_data;  //成员变量用于保存字符串
};


#endif //C__LEARNING_STRING_H
