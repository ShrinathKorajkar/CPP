#include <vector>
#include <iostream>

struct MyClass
{
    MyClass() {}
    MyClass(const MyClass &) { std::cout << "Copy\n"; }
    MyClass(MyClass &&) noexcept { std::cout << "Move\n"; }
};

int main()
{
    std::vector<MyClass> v;
    v.push_back(MyClass());
    v.push_back(MyClass()); // will prefer move if noexcept, if noexcept removed, will call copy
}
