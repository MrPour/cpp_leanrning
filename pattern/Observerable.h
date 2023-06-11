//
// Created by mrpour on 2023/3/6.
//
#ifndef C__LEARNING_OBSERVERABLE_H
#define C__LEARNING_OBSERVERABLE_H

//让编译器去工程中找Observer这个类
class Observer;

#include "Observer.h"
#include "stdio.h"
#include "list"
#include "string"
using namespace std;

/**
 * 被观察者类
 */
class Observable
{
public:
    Observable():_Change(false){};
    virtual ~Observable();
    //注册观察者
    void Attach(Observer* pOb);
    //删除注册观察者
    void Detach(Observer* pOb);
    //删除所有注册观察者
    void DetachAll()
    {
        _Obs.clear();
    };
    //获取注册列表中注册者的数目
    int GetObserverCount()
    {
        return _Obs.size();
    };
//【与java不同】：严格子类才能访问，同包之间都不能访问
protected:
    //改变状态
    void SetChange(string news);
    //【与java不同】：virtual的方法才能支持子类重写
    virtual void GetSomeNews(string str);

private:
    //有变化需要通知
    //【与java不同】：void*指针可以等于任何类型的指针,但是反过来不可以,需要强制类型转换
    void Notify(void* pArg);
private:
    //观察者对象列表【双向链表】
    list<Observer*> _Obs;
    //当前是否发生变化
    bool _Change;

};
#endif //C__LEARNING_OBSERVERABLE_H
