//
// Created by mrpour on 2023/5/7.
//
#include <map>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct Display{
    void operator()(pair<string,double> entry)
    {
        cout<<entry.first<<":"<<entry.second<<endl;
    }
};
int main()
{
    //3种插入的方法
    map<string,double> studentScores;
    //此方法只能初始化，不能修改！
    studentScores.insert(pair<string,double>("James",100));
    //此方法除了初始化，也可修改！
    studentScores["James"] = 98.5;
    studentScores.insert(pair<string,double>("Kobe",98.5));
    studentScores.insert(pair<string,double>("Jordan",99.5));
    studentScores.insert(map<string,double>::value_type ("Curry",97.5));

    //遍历map
    for_each(studentScores.begin(),studentScores.end(),Display());


    //按key查找
    //find方法返回迭代器，迭代器指向pair的指针
    map<string,double>::iterator itr = studentScores.find("Kobe1");
    if(itr!=studentScores.end())
    {
        cout<<itr->second<<endl;
    }else
    {
        cout<<"No such element error!"<<endl;
    }


    //while遍历查找
    map<string,double>::iterator itr2 = studentScores.begin();
    while(itr2 != studentScores.end())
    {
        if(itr2->second < 98.0)
        {
            //【与java不同】java不可以在迭代过程中用容器方法删除，只能用迭代器的方法删除
            //防止迭代器失效，不能在使用迭代器递增之前删除当前的迭代器，确保itr2指针一直指向元素！！！
            studentScores.erase(itr2++);
        }
        else
        {
            itr2++;
        }
    }

    for_each(studentScores.begin(),studentScores.end(),Display());

    //for遍历查找
    for(map<string,double>::iterator i = studentScores.begin();i!=studentScores.end();i++)
    {
        if(i->second < 99.5)
        {
            //防止迭代器失效，让当前迭代器永远指向有pair值的位置（返回值为下一个位置的迭代器）
            i = studentScores.erase(i);
        }
    }
    for_each(studentScores.begin(),studentScores.end(),Display());

    return 0;
}