//
// Created by mrpour on 2023/5/8.
//
#include "iostream"
#include "algorithm"
#include "vector"
#include <assert.h>
using namespace std;
//交换函数
void swap(char* a,char* b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
//pStr -- 字符串的首地址  pPosition -- 本次遍历的开始地址
//动态规划问题 -- 两个状态之间的联系：swap ，即递归单元
void permutation(char* pStr,char* pBegin)
{
    assert(pStr && pBegin);
    //递归结束条件
    if(*pBegin =='\0')
    {
        //对原始字符串进行修改到底后触发打印
        cout<<pStr<<endl;
    }
    else
    {
        for(char*p = pBegin;*p!='\0';p++)
        {
            swap(p,pBegin);
            permutation(pStr,pBegin+1);
            swap(p,pBegin);
        }
    }

}
int main()
{
    char test[] = "abc";
//    permutation(test,test);

    //要了解stl提供的全排列函数其使用的要求，以及规则，如此处传入的字符串数组必须按顺序排列。
    do
    {
       cout<<test<<endl;
    }while(next_permutation(test,test+3));

    char test2[] = "cba";
    do
    {
        cout<<test<<endl;
    }while(prev_permutation(test2,test+3));
    return 0;
}