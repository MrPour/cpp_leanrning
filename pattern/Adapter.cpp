//
// Created by mrpour on 2023/5/4.
//
#include "iostream"
using namespace std;

class OldTool{
public:
    OldTool(int x,int y):_x(x),_y(y){};
    void oldMethod()
    {
        cout<<"old one "<<_x<<" "<<_y<<endl;
    }
private:
    double _x;
    double _y;
};

//对需要增强的方法进行一个接口暴露，抽象类通常用做接口继承
class NewTool{
public:
    virtual void newMethod(string str) = 0;
};
//1、使用组合的方式完成适配器
//适配器连接2个类
class ToolAdaptor:public NewTool{
private:
    OldTool _oldTool;
public:
    ToolAdaptor(double x,double y): _oldTool(x+y,y){}
    void newMethod(string str){
        cout<<"new method in combination"<<endl;
        _oldTool.oldMethod();
    }
};

//2、使用继承的方式完成适配器
//适配器连接2个类
class ToolAdaptor2:public NewTool,private OldTool{
public:
    ToolAdaptor2(double x,double y): OldTool(x+y,y){}
    void newMethod(string str){
        cout<<"new method in extend"<<endl;
        oldMethod();
    }
};
int main()
{
    double x=100.0,y=200.0;
    ToolAdaptor ta(x,y);
    NewTool* pnt = &ta;
    pnt->newMethod("new");

    ToolAdaptor2 ta2(x,y);
    NewTool* pnt2 = &ta2;
    pnt2->newMethod("new");
    return 0;
}
