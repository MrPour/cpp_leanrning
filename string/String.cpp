//
// Created by mrpour on 2023/3/4.
//

#include "String.h"
String::String(const char* str)
{
    if(str == NULL)
    {
        //开辟数组空间
        m_data = new char[1];
        if(m_data != NULL)
        {
            //对数组赋值
            *m_data = '\0';
        }
        else
        {
            exit(-1);
        }
    }
    else
    {
        int len = strlen(str);
        //字符串的数组以/0结尾
        m_data = new char[len+1];
        if(m_data != NULL)
        {
            strcpy(m_data,str);
        }
        else
        {
            exit(-1);
        }
    }
}

String::String(const String& other)
{
    int len = strlen(other.m_data);
    //字符串的数组以/0结尾
    m_data = new char[len+1];
    if(m_data != NULL)
    {
        strcpy(m_data,other.m_data);
    }
    else
    {
        exit(-1);
    }
}
//移动构造函数：通过move方法获取String&&
String::String(String&& other)
{
    if(other.m_data != NULL)
    {
        //资源让渡
        m_data = other.m_data;
        other.m_data = NULL;
    }
}

//重载运算符=，属于深拷贝
String& String::operator=(const String& other) {
    if (this != &other)
    {
        //释放原有内容
        delete[] m_data;
        //重新分配资源并赋值
        int len = strlen(other.m_data);
        //字符串的数组以/0结尾
        m_data = new char[len + 1];
        if (m_data != NULL) {
            strcpy(m_data, other.m_data);
        } else {
            exit(-1);
        }
    }
    return *this;
}
//重载运算符=，属于深拷贝
String& String::operator=(String&& other)noexcept
{
    if(this!=&other)
    {
        delete[] m_data;
        m_data = other.m_data;
        other.m_data = NULL;
    }
    return *this;
}
//【与java不同】：类似于java 每个类重写toString方法，这里是直接把cout<<进行了个性化重写
ostream& operator<<(ostream& os,const String& str)
{
    //传统的os智能打印数组和字符串，不能打印对象
    os << str.m_data <<endl;
    return os;
}

String::~String() {
    if(m_data!=NULL)
    {
        delete[] m_data;
    }
}