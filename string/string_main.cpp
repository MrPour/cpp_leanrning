//
// Created by mrpour on 2023/3/6.
//
#include "String.h"
using namespace std;
int main() {
    String s0;
    String s("a");
//    String s2 = move(s);
    String s3(move(s));
    //【与java不同】：入参不同，实现不同
    cout<<s3<<endl;
    return 0;
}