//
// Created by mrpour on 2023/5/5.
//

#include "iostream"
#include <string.h>

template<class T>
T Max(T a,T b)
{
    return a>b ? a:b;
}
//特化(特殊匹配)编译器当检测到普通函数和模板都可以使用时，优先使用普通函数
template<>
char* Max(char* a,char* b)
{
    return strcmp(a,b)>0 ? a:b;
}

template<class T1,class T2>
int Max(T1 a,T2 b)
{
    return static_cast<int>(a>b?a:b);
}

using namespace std;
int main()
{

//    cout<<Max('a','b')<<endl;
//    cout<<Max(1,2.5)<<endl;
    cout<<Max("aaa","bbb")<<endl;

}