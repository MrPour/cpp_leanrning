#include <iostream>
#include <limits>
#include "fstream"
using namespace std;
int main()
{
    int buffer;
    int index = 0;
    //1、定义输出流
    fstream fout;
    //2、选择模式打开文件
    fout.open("testBuffer.txt",ios::app);
    //3、判断是否打开成功
    if(!fout)
    {
        cout << "open file failed!" << endl;
    }
    //4、文件操作
    while(cin >> buffer)
    {
        fout << "this number is "<<buffer<<endl;
        index ++ ;
        if(index == 5)
        {
            break;
        }
    }

    //清空缓冲区
    cin.ignore(numeric_limits< std::streamsize>::max(), '\n');

    char ch;
    cin>>ch;
    fout<<"the last letter is " <<ch <<endl;

    //5、关闭流
    fout.close();
    cout<<"写入完成"<<endl;
    return 0;
}