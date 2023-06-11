//
// Created by mrpour on 2023/5/8.
//
#include "iostream"
#include "algorithm"
using namespace std;

template<class T>
//仿函数--把函数类化
struct SortF{
    //inline优化
    //const& 传入指针，如果T是自定义类的话会避免拷贝
    inline bool operator()(T const& a,T const& b)
    {
        //如果T是自定义类，需要重写自己的<
        return a<b;
    }
};

template<class T>
struct Display{
    inline void operator()(T const& a)
    {
        //如果T是自定义类，需要重写自己的cout
        cout<<a<<" ";
    }
};

int main(){
    int arr[]={5,9,3,1,8,0};
    sort(arr,arr+6,SortF<int>());
    for_each(arr,arr+6,Display<int>());
    return 0;
}