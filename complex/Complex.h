//
// Created by mrpour on 2023/3/2.
//

#ifndef UNTITLED_COMPLEX_H
#define UNTITLED_COMPLEX_H
#include <iostream>
using namespace std;

class Complex {
public:
    Complex(); //无参构造 -- 重写以免被覆盖

//    //【参数列表】可以在头文件中以参数列表的形式队成员变量完成赋值操作更加优化
//    Complex(double _real,double _image):_real(_real),_image(_image){};

    //【含参构造】
    Complex(double _real,double _image);
    //【拷贝构造】
    Complex(const Complex& x);
    //【与java不同】：析构函数 -- 销毁时调用
    virtual ~Complex();//
    // 【const成员函数】：(1)避免函数内部修改成员变量 (2)可被const函数调用
    double getReal() const{
        return this->_real;
    }
    void setReal(double d){
        this->_real = d;
    }
    double getImage() const{
        return this->_image;
    }
    void setImage(double i){
        this->_image = i;
    }

    //【与java不同】：支持运算符重载
    //const Complex& -- 1、避免通过x改变原来数据  2、x可以接收const和非const的参数
    //const 修饰+  -- 使得操作符可以被const的函数所调用！！！
    Complex operator+(const Complex& x) const;

    //赋值操作重载，返回引用
    Complex& operator=(const Complex& x);

    //前置++重载
    Complex& operator++();

    //后置++重载
    //（int）为区分前后置，后置++需要定义int参数
    //由于既要改变this的值，又要返回原先的this，值是全新的，所以此处不能返回引用了
    Complex operator++(int);

    //+=重载
    Complex& operator+=(const Complex& x);

    //==重载，相当于java里重写equals函数
    bool operator==(const Complex& x);

    // !=重载
    bool operator!=(const Complex& x);

    //将重载的<<符号定义为友元(运算符),因为运算符的定义内要访问私有变量
    friend ostream& operator<<(ostream& os,const Complex& x);//打印可能重复使用，因此返回值为其指针
    friend istream& operator>>(istream& is,Complex& x);//可以对输入的值做改变

private:
    double _real;//虚部
    double _image;//实部
};
#endif //UNTITLED_COMPLEX_H
