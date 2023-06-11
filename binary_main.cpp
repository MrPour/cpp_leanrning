//
// Created by mrpour on 2023/3/4.
//
#include <iostream>
#include <limits>
#include "fstream"
#include "string"
using namespace std;
static const int bufferLen=2048;
bool CopyFile(const string& src,const string& dst)
{
    //打开源文件和目标文件
    //源文件以二进制的方式读操作打开
    //目标文件以二进制的方式写操作打开，并且清除原内容
    ifstream in(src.c_str(),ios::in|ios::binary);
    ofstream out(dst.c_str(),ios::out|ios::binary|ios::trunc);
    //判断文件打开是否成功，失败返回false
    if(!in||!out)
    {
        return false;
    }
    //源文件中读取数据，写到目标文件中
    //通过读取源文件的EOF判断是否读写结束
    char temp[bufferLen];
    while(!in.eof())
    {
        in.read(temp,bufferLen);
        streamsize bufferLenCount = in.gcount();
        out.write(temp,bufferLenCount);
    }
    //关闭源文件和目标文件
    in.close();
    out.close();
    return true;
}
int main()
{
    cout<<CopyFile("lizhi.mp3","lizhizhuangbi.mp3");
    return 0;
}