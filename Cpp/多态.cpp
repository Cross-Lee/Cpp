#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void speak() // 添加virtual关键字，地址晚绑定，运行阶段绑定
    {
        cout << "Animal is speaking" << endl;
    }
};

class Cat : public Animal
{
public:
    void speak()
    {
        cout << "Cat is speaking" << endl;
    }
};

void Speak(Animal &animal)
{
    animal.speak();
}

int main()
{
    Cat cat;
    
    // 输出是animal，原因是早绑定(编译阶段绑定)
    Speak(cat); // 行参是父类，但是实参是子类，不需要转化
    
}

// 动态多态条件：
// 1. 有继承关系
// 2. 需要重写父类虚函数
// 动态多态实现：
// 1. 父类指针指向子类对象
// 2. 多态的原理：
// - 子类继承父类，会继承父类的虚函数指针，指向父类虚函数表，表内记录虚函数地址
// - 子类重写虚函数，使得虚函数指针指向子类虚函数表，表内记录子类虚函数地址