#include <iostream>
#include <string>
using namespace std;

class A
{
    friend void fun(A *a); // 通过声明友元函数来使得类外函数访问类内私有成员
    // 友元类是一样的
    // 其他类的成员函数也是一样的

public:
    A()
    {
        m_s = "day";
    }
private:
    string m_s;
};

void fun(A *a)
{
    cout << a->m_s << endl;
}

int main()
{
    A a;
    fun(&a);
    return 0;
}