#include <iostream>
using namespace std;

class vir
{
public:
    // virtual vir() {} // 错误。没有虚构造函数
    virtual ~vir() {}
    virtual void size()
    {

    }
};

int main()
{
    // 当类中有虚函数时，生成一个指向虚函数表的指针
    // 虚函数表中存储虚函数地址
    cout << sizeof(vir) << endl;
}

// https://jacktang816.github.io/post/virtualfunction/