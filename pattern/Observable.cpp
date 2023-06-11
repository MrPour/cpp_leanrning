//
// Created by mrpour on 2023/3/6.
//
#include "Observerable.h"
//注册观察者
void Observable::Attach(Observer* pOb)
{
    if(pOb == NULL)
    {
        return;
    }
    //返回迭代器，当前指向第一个元素
    auto it=_Obs.begin();
    for(;it != _Obs.end();it++)
    {
        //判断当前列表是否已经存在pOb
        if(*it == pOb)
        {
            return;
        }
    }
    _Obs.push_back(pOb);
}

//删除观察者
void Observable::Detach(Observer* pOb)
{
    if(pOb==NULL || _Obs.empty())
    {
        return;
    }
    _Obs.remove(pOb);

}

//状态
void Observable::SetChange(string news)
{
    _Change = true;
    Notify((void*)news.c_str());
}

//通知
void Observable::Notify(void* pArg){
    if(!_Change)
    {
        //无消息，不通知
        return;
    }
    //返回迭代器，当前指向第一个元素
    auto it=_Obs.begin();
    for(;it != _Obs.end();it++)
    {
        (*it)->Update(pArg);
    }
    _Change = false;
}

