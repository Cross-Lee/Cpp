#include <iostream>
using namespace std;

class A
{
public:
    A()
    {
        cout << "Create A" << endl;
    }
    ~A()
    {
        cout << "Destroy A" << endl;
    }
};

class B
{
public:
    B(A a) : m_a(a)
    {
        cout << "Create B" << endl;
    }

    ~B()
    {
        cout << "Destroy B" << endl;
    }
public:
    A m_a;
};

int main()
{
    // 不知道为什么没有输出
    B b(A a);
    return 0;
}

// 当类中包含另外一个类的类对象时，先调用另外的构造函数，析构函数的调用顺序则相反

