#include <iostream>
using namespace std;

class Person
{
public:
    Person(int age)
    {
        this->age = age; // this解决名称冲突
    }

    // 需要使用引用类型
    Person& PersonAddAge(Person &p) // 返回值为引用类型，则返回自身，返回值没有引用，则返回一个新的对象（详情参见拷贝构造函数）
    {
        this->age += p.age;
        return *this; // 返回本体
    }

public:
    int age;
};

int main()
{
    Person p1(10);
    Person p2(2);

    p1.PersonAddAge(p2).PersonAddAge(p1).PersonAddAge(p2);

    cout << p1.age << endl;
    return 0;
}