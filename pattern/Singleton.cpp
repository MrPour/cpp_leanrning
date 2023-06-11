//
// Created by mrpour on 2023/3/6.
//

#include "Singleton.h"

//初始化成员变量--懒汉式【与java不同】不需要花括号也可以初始化
Singleton* Singleton::This = NULL;
//初始化成员变量--饿汉式
//Singleton* Singleton::This = new Singleton();
//初始化静态方法
const Singleton* Singleton::getInstance()
{
    //判断是否初始化
    if(!This)
    {
        //在内部调用无参构造函数
        This = new Singleton();
    }
    return This;
}
Singleton::Singleton() {

}