//
// Created by ruish on 2023/7/17.
//
#include <iostream>
using namespace std;

template <class T>
class Vector{
private:
    //vector可存储的大小
    int capacity;
    //底层的数组
    T* array;
    //扩展数组空间
    void resize(int size){
        if(size <= capacity) return ;
        T* temp = new T[size];
        for(int ii=0 ; ii < capacity; ++ii)
        {
            temp[ii] = array[ii];
        }
        delete[] array;
        array = temp;
        capacity = size;
    }
public:
    Vector(int size):capacity(size){
        //初始化数组
        array = new T[capacity];
    }
    ~Vector()
    {
        delete[] array;array = nullptr;
    }
    Vector& operator=(const Vector& v)
    {
        delete [] array;
        array  = new T[v.capacity];
        for(int ii=0;ii < v.capacity;++ii)
        {
            array[ii] = v[ii];
        }
        return *this;
    }

    //重载操作符[]，能读取能修改
    T& operator[](int index){
        if(index >= capacity) this->resize(index+1);
        return array[index];
    }

    //重载操作符[]，const对象使用，只能读取不能修改
    const T& operator[](int index)const{
        return array[index];
    }
};

int main()
{
    Vector<string> v(5);
    v[0] = "1";
    v[1] = "2";
    v[6] = "7";
    Vector<string> v2 = v;
    cout<<v2[6]<<endl;
    return 0;
}
