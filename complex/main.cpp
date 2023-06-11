#include "Complex.h"
void GetMemory(char *p)
{
    *p='B';
}
void Test(void)
{
    char temp[] ="LA";
    char* str = temp;
    GetMemory(str);
    cout<<temp<<endl;
}
int main() {
    Complex a(1.0,2.0);
    Complex e;
    //输入接收的变量--e
    cin >> e;
    e+=a;
    //输出接收的变量--e
    cout << e << endl;
    return 0;
    Test();
    return 0;
}
