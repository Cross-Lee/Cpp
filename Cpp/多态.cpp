#include <iostream>
#include <string>
using namespace std;

class Animal
{
public:
    Animal()
    {
        cout << "Animal的构造函数" << endl;
    }

    virtual void speak() = 0; // 添加virtual关键字，地址晚绑定，运行阶段绑定

    virtual ~Animal() // 声明为虚析构函数才能释放子类对象
    {
        cout << "Animal的析构函数" << endl;
    }

    // virtual ~Animal() = 0; // 如果是纯虚析构 需要在类外具体实现
};

class Cat : public Animal
{
public:
    Cat(string name)
    {
        cout << "Cat的构造函数" << endl;
        m_name = new string(name);
    }

    void speak()
    {
        cout << "Cat is speaking" << endl;
    }

    ~Cat()
    {
        if (this->m_name != nullptr)
        {
            cout << "Cat的析构函数" << endl;
            delete m_name;
            m_name = nullptr;
        }
    }

public:
    string *m_name;
};

int main()
{
    Animal *animal = new Cat("Tom");
    animal->speak();
    delete animal;
    // Cat cat("Tom");
    
    // // 输出是animal，原因是早绑定(编译阶段绑定)
    // Speak(cat); // 行参是父类，但是实参是子类，不需要转化
    return 0;
    
}

// 动态多态条件：
// 1. 有继承关系
// 2. 需要重写父类虚函数
// 动态多态实现：
// 1. 父类指针指向子类对象
// 2. 多态的原理：
// - 子类继承父类，会继承父类的虚函数指针，指向父类虚函数表，表内记录虚函数地址
// - 子类重写虚函数，使得虚函数指针指向子类虚函数表，表内记录子类虚函数地址

// 纯虚函数
// + virtual 关键字，返回值 = 0（）
// 当类中有了纯虚函数，类也叫抽象类
// 抽象类不能实例化
// 子类必须重写抽象类，否则也是抽象类
// 通过一个父类指针，调用不同的子类函数

// 虚析构与纯虚析构
// 解决父类指针释放子类对象的问题
// 都需要具体函数实现
// 如果纯虚析构，该类属于抽象类，无法实例化