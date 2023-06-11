//
// Created by mrpour on 2023/3/1.
//
#include "Complex.h"
#include <iostream>
using namespace std;
Complex::Complex() {
    this->_real = 0.0;
    this->_image = 0.0;
    cout << "无参构造" << endl;
}

// 如果不使用【参数列表】，含参构造如下，二者等价
Complex::Complex(double _real, double _image) {
    this->_image = _image;
    this->_real = _real;
    cout << "含参构造" << endl;
}

Complex::Complex(const Complex& x) {
    _image = x._image;
    _real = x._real;
    cout << "拷贝构造" << endl;
}

Complex::~Complex() {
    cout << "~Complex" << endl;
}

Complex Complex::operator+(const Complex &x)const {
//    Complex temp;
//    temp._real = this->_real + x._real;
//    temp._image = this->_image + x._image;
//    return temp; // 触发拷贝，创建一个新对象,但是很奇怪的是clion在此处优化了临时对象，导致出括号时没有调用拷贝构造生成对象！！！
    return Complex(this->_real+x._real,this->_image+x._image);//此种方法避免了临时对象产生。。但是效果好像不明显啊，和上面的结果相同
}

Complex& Complex::operator=(const Complex &x) {
    if(this != &x)
    {
        this->_real = x._real;
        this->_image = x._image;
    }
    return *this;
}

Complex& Complex::operator++()
{
    this->_image++;
    this->_real++;
    return *this; //返回this指针指向的对象，使用引用指向这个对象（指针只有在指向不会析构的情况下才能使用）
}

Complex Complex::operator++(int)
{
    //【注】后置++需要完成两个任务，1是this的属性值+1 2是返回改变前的对象
     return Complex (this->_real++,this->_image++);//返回之前的对象，为了省去中间变量，使用此方法返回（此处无其他永久变量，只能返回对象）
}

Complex& Complex::operator+=(const Complex &x)
{
    this->_real += x._real;
    this->_image += x._image;
    return *this;
}

bool Complex::operator==(const Complex &x){
    return (this->_real == x._real) && (this->_image == x._image);
}

bool Complex::operator!=(const Complex &x){
    return !(this->_real == x._real && this->_image == x._image);
}

ostream& operator<<(ostream& os,const Complex& x)
{
    //这里对cout的<<进行封装，os就是cout，x是<<的变量
    os << "real value is "<<x._real<<",image value is "<<x._image;
    return os;
}

istream& operator>>(istream& is,Complex& x)
{
    //第一个值给real 第二个值给image
    is>>x._real>>x._image;
    return is;
}
