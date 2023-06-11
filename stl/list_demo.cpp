//
// Created by mrpour on 2023/5/8.
//
#include "iostream"
#include "algorithm"
#include "list"
using namespace std;

int main(){
    list<int> v;
    //添加，去除则是pop
    v.push_back(1);
    v.push_back(3);
    v.push_front(9);
    v.push_front(10);

    list<int>::iterator i;
    for(i = v.begin();i != v.end();i++)
    {
        (*i)++;
        cout<<*i<<" ";
    }
    cout<<endl;

    //尾部迭代，所获取的迭代器都需要添加r
    list<int>::reverse_iterator ri;
    for(ri = v.rbegin();ri != v.rend();ri++)
    {
        (*ri)++;
        cout<<*ri<<" ";
    }
    cout<<endl;
    return 0;
}