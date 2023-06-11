//
// Created by mrpour on 2023/5/8.
//
#include "iostream"
#include "algorithm"
#include "vector"
using namespace std;

int main(){
    //transform和lambda表达式
    int ones[]={5,9,3,1,8};
    int twos[]={1,2,3,4,5};
    int result[5];
    transform(ones,ones+5,twos,result,plus<int>());
    //[]表示来自方法调用外部的变量，()则表示来自方法调用内部的变量
    for_each(result,result+5,[](int a)->void{
        cout<<a<<endl;
    });
    int arr[] = {0,1,2,3,4,4,5,6,6,7,7,7,8};
    int len = sizeof(arr)/sizeof(arr[0]);
    //统计值的个数
    int total = count(arr,arr+len,6);
    cout << count_if(arr,arr+len,[](int a)->bool{
        return a>7;
    });
    //二分查找
    cout<< binary_search(arr,arr+len,6)<<endl;
    vector<int> iA(arr+2,arr+6);
    //查找某个序列出现的位置
    cout<<*search(arr,arr+len,iA.begin(),iA.end());
    return 0;
}