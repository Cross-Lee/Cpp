#include <iostream>
using namespace std;

class A
{
public:
    static int s_a; 
    int m_a;
private:
    int m_b;
protected:
    int m_c;
};
int A::s_a = 100;

class B : public A // 这里的默认是私有继承，会使继承的属性变为私有
{
public:
    static int s_a;
    int m_B;
};
int B::s_a = 200;

int main()
{
    cout << sizeof(B) << endl; // 无论什么样的继承，所有权限的成员都会被继承
    cout << "通过类的对象访问静态成员" << endl;
    B b;
    cout << "A的静态成员变量" << b.s_a << endl;
    cout << "B的静态成员变量" << b.A::s_a << endl;

    cout << "通过类的作用域访问静态成员" << endl;
    cout << "A的静态成员变量" << B::s_a << endl;
    cout << "B的静态成员变量" << B::A::s_a << endl; // 第一个::代表类名方式，第二个::代表父类作用域
    return 0;
}

// 构造函数的顺序是：先构造父类，再构造子类；析构函数的顺序相反
// 继承中出现同名，调用子类，父类需要添加类的名称
// 继承中的同名，子类会覆盖父类的重载，即调用父类，都需要添加作用域
// 多继承语法，可以继承多个父类，但是父类中同名函数仍然需要添加作用域
// 菱形继承：
// - 菱形继承可能会产生数据重复的问题，即两个父类包含相同的数据，但是实际上可能不需哟啊
// - 因此，引入虚继承，virtual关键字
// virtual关键字会引入vbptr，指向vbtable，vbtable储存偏移量（地址）