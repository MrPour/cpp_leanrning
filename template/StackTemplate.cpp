//
// Created by ruish on 2023/7/17.
//
#include <iostream>
using namespace std;

template <class DataType>
class Stack{
private:
    //栈的大小
    int stack_size;
    //底层的数组
    DataType* array;
    //栈顶索引(能存放的下一个位置)
    int topIndex;
public:
    Stack(int size):stack_size(size),topIndex(0){
        //初始化数组
        this->array = new DataType[size];
    }

    ~Stack()
    {
        delete[] this->array;this->array = nullptr;
    }

    bool isEmpty() const
    {
        return topIndex == 0;
    }

    bool isFull() const
    {
        return topIndex == stack_size;
    }

    bool push(const DataType& data)
    {
        if(topIndex < stack_size) {array[topIndex++] = data;return true;}
        return false;
    }

    bool pop(DataType& data)
    {
        if(topIndex > 0) {data = array[--topIndex];return true;}
        return false;
    }
};

int main()
{
    Stack<string> ss(5);
    ss.push("1"); ss.push("2"); ss.push("3"); ss.push("4"); ss.push("5");
    string data;
    while(!ss.isEmpty())
    {
        ss.pop(data);
        cout <<"弹出元素:"<< data << endl;
    }
    return 0;
}
