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