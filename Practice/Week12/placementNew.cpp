#include <iostream>
#include <new>     // for placement new
#include <cstddef> // for std::size_t, std::max_align_t
#include <cassert>

struct MyClass
{
    int a;
    MyClass() : a(0) { std::cout << "Constructed\n"; }
    MyClass(const int &a) : a(a) { std::cout << "Constructed\n"; }
    ~MyClass() { std::cout << "Destructed\n"; }
};

int main()
{
    // misalignment can lead to crash - SIGBUS as CPU required data to be aligned
    alignas(MyClass) char buffer[3 * sizeof(MyClass)];
    alignas(std::max_align_t) char buffer[64]; // aligned for any built-in type (16 -> long double)

    MyClass *p1 = new (buffer) MyClass(10);
    MyClass *p2 = new (buffer + sizeof(MyClass)) MyClass(20);
    MyClass *p3 = new (buffer + 2 * sizeof(MyClass)) MyClass(30);

    // Manually destroy them
    p1->~MyClass();
    p2->~MyClass();
    p3->~MyClass();
}
