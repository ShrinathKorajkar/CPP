#include <iostream>
#include <utility> // std::move

class MyClass
{
public:
    void show() & // Only for lvalues
    {
        std::cout << "Called on lvalue\n";
    }

    void show() && // Only for rvalues
    {
        std::cout << "Called on rvalue\n";
    }
};

int main()
{
    MyClass obj;
    obj.show(); // lvalue version called, if lvalue version not defined, will give error

    MyClass().show(); // rvalue version called

    std::move(obj).show(); // rvalue version called
}
