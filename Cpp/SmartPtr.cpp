#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Init
{
public:
    Init()
    {
        cout << "Create Init." << endl;
    }

    ~Init()
    {
        cout << "Destroy Init." << endl;
    }

    void print() {}
};

int main()
{
    // Unique智能指针，自动释放内存，不能拷贝构造
    {
        cout << "Unique_Ptr: "
             << "\n";
        // 构造智能指针
        unique_ptr<Init> Uinit1 = make_unique<Init>(); // 初始化方式1（更好）  应对异常更好
        Uinit1->print();
        // unique_ptr<Init> Uinit2(new Init()); // 初始化方式2
        // Uinit2->print();
    }

    cout << "******************" << endl;
    // shared_ptr智能指针，包含一个block域，用来计数（指向对象的数量），
    // 当计数区为0时，才会销毁栈，允许拷贝构造
    {
        cout << "Shared_ptr:" << endl;
        shared_ptr<Init> Sinit1 = make_shared<Init>();
        // shared_ptr<Init> Sinit2(new Init());
        shared_ptr<Init> S = Sinit1;
    }

    cout << "******************" << endl;
    // Weak_ptr可以被复制，但是不会增加控制块来计数，仅仅声明指针还活着
    {
        cout << "Weak_ptr:" << endl;
    }

    return 0;
}