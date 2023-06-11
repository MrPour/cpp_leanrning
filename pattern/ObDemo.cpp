//
// Created by mrpour on 2023/3/6.
//
#include "Observer.h"
#include "Observerable.h"
class News:public Observable
{
public:
    void GetSomeNews(string str)
    {
        SetChange("News:"+str);
    }
};

class User1:public Observer
{
    void Update(void* pArg)
    {
        cout<<"User1 got news"<<endl;
    }
};

class User2:public Observer
{
    virtual void Update(void* pArg)
    {
        cout<<"User2 got news"<<endl;
    }
};

int main()
{
    User1 u1;
    User2 u2;
    News n1;
    n1.GetSomeNews("T0");
    cout<<"当前订阅者："+n1.GetObserverCount()<<endl;

    n1.Attach(&u1);
    n1.Attach(&u2);
    n1.GetSomeNews("T1");
    cout<<"当前订阅者："+n1.GetObserverCount()<<endl;

    n1.Detach(&u2);
    n1.GetSomeNews("T2");
    cout<<"当前订阅者："+n1.GetObserverCount()<<endl;

    n1.DetachAll();
    n1.GetSomeNews("T3");
    cout<<"当前订阅者："+n1.GetObserverCount()<<endl;
}
