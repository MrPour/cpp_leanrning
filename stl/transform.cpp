//
// Created by mrpour on 2023/5/8.
//
#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
using namespace std;

int main(){
    int arr[] = {1,2,3,4,5};
    int add[] = {10,20,30,40,50};
    int result[5];
    //transform:对区间中的内容进行变换操作
    transform(arr,arr+5,add,result,plus<int>());
    //[]-接收for_each外部的参数；()-接收for_each内部的参数
    for_each(result,result+5,[](int a)->void{
        cout<<a<<" ";
    });

    int exam[] = {1,1,2,2,3,4,5,5,5,5,5};
    //【与java不同】C++数组未提供length方法
    int length = sizeof(exam)/sizeof(exam[0]);
    cout<<count(exam,exam+length,5)<<endl;
    return 0;
}