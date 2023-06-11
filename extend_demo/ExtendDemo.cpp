//
// Created by mrpour on 2023/3/6.
//

//public继承的原则：
//父类的方法子类不能修改，如果要重写，必须将父类的该方法定义为虚函数virtual,否则无法重写
//尽量扩充代码而不是修改
#include "iostream"
using namespace std;
class Shape{
public:
    // virtual：意味着子类可以重写这个函数
    virtual double Area(){
        cout<<"此方法为求面积方法"<<endl;
    }

    //当virtual的方法=0时，此类为抽象类，无自己的实现。
//    virtual double Area()=0;
    void Display(){
        cout<<Area()<<endl;
    }
};

class Square : public Shape{
public:
    Square(double len):length(len){};
    //子类重写父类方法
    double Area(){
        return length*length;
    }
private:
    double length;
};

class Circle : public Shape{
public:
    Circle(double r):radius(r){};
    //子类重写父类方法
    double Area(){
        return 3.14*radius*radius;
    }
private:
    double radius;
};

class Triangle : public Shape{
public:
    //【与java不同】：通过参数列表构造函数，可以优化初始化
    Triangle(double len,double hi):length(len),height(hi){};
    //子类重写父类方法
    double Area(){
        return 0.5*length*height;
    }
private:
    double length;
    double height;
};

int main()
{
    const int shapeNum = 3;
    Square s1(2.0);//此子类对象中包含自己成员变量和父类对象（虚函数表+成员）
    Circle c1(2.0);
    Triangle t1(2.0,3.0);

    //用父类调用子类的方法
    Shape* shapes[2];
    shapes[0] = &s1;
    shapes[1] = &c1;
    shapes[2] = &t1;
    for(unsigned int index = 0;index < shapeNum;index++)
    {
        shapes[index]->Display();
    }
    return 0;
}