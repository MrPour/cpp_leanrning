//
// Created by mrpour on 2023/3/6.
//
#include "stdio.h"
#include "iostream"
using namespace std;
#ifndef C__LEARNING_OBSERVER_H
#define C__LEARNING_OBSERVER_H
/**
 * 观察者类
 */
class Observer {
public:
    Observer(){};
    virtual ~Observer(){};

    // 抽象类--当被观察对象变化时，通知被观察者调用此方法
    virtual void Update(void* pArg) = 0;
};


#endif //C__LEARNING_OBSERVER_H
