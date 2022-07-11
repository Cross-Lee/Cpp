#include <iostream>
using namespace std;

class A
{
public:
//     int a;
//     int b;
//     int c;
//     int d;
};

int main()
{
    A a; // a储存了对象中所有的数据
    cout << "栈创建对象：" << sizeof(a) << endl; // 空类只有一个字节，用来占位、区分、实例化
    A *b = new A(); // b是一个指针类型
    cout << "堆创建对象：" << sizeof(b) << endl; 
    cout << "指针大小："   << sizeof(A*) <<endl;

}