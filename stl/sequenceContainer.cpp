//
// Created by mrpour on 2023/5/7.
//
#include "iostream"
#include <list>
#include <vector>
#include <deque>
#include <algorithm>

#include <queue>
#include <stack>

using namespace std;
//将函数定义为对象使用
struct Display{
    //重载Display的()符号，即函数式使用
  void operator()(int a)
  {
      cout<<a<<" ";
  }
};
int main()
{
    int arr[] = {1,2,3,4,5};
    //左闭右开
    vector<int> IVector(arr,arr+5);
    list<int> IList(arr,arr+5);
    //双端队列
    deque<int> IDequeue(arr,arr+5);

    //栈，队列可以通过对双端队列适配的方式来实现
    queue<int> IQueue(IDequeue); //队列，先进先出
    stack<int> IStack(IDequeue); //栈，后进先出

    //优先队列
    priority_queue<int> IPQueue(arr,arr+5);//优先队列，按优先权

    //从初始值到末尾值遍历执行函数
    for_each(IVector.begin(),IVector.end(),Display());
    cout<<endl;

    //通过弹出遍历
    while(!IQueue.empty())
    {
        cout<<IQueue.front()<<" ";
        IQueue.pop();
    }
    cout<<endl;

    while(!IStack.empty())
    {
        cout<<IStack.top()<<" ";
        IStack.pop();
    }
    cout<<endl;

    while(!IPQueue.empty())
    {
        cout<<IPQueue.top()<<" ";
        IPQueue.pop();
    }
    return 0;
}