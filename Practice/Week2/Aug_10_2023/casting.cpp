#include <iostream>

class Base
{
    virtual void foo() {}
};
class Derived : public Base
{
};

int main()
{
    // static - numeric types, upcasting, make sense logically, compile time check
    int num = 42;
    double result = static_cast<double>(num);

    std::cout << "static_cast result: " << result << std::endl;

    const int num2 = 42;

    // const_cast - compile time
    int *nonConstPtr = const_cast<int *>(&num2);
    *nonConstPtr = 99;

    // reinterpret_cast example - unsafe, bitwise reinterpretation, no type check, no runtime check
    void *voidPtr = reinterpret_cast<void *>(&num);
    int *numPtr = reinterpret_cast<int *>(voidPtr);

    // dynamic casts - both compile and runtime check - safe
    Base *b = new Derived();
    Derived *d = dynamic_cast<Derived *>(b);

    delete b;

    std::cout << "numPtr value: " << *numPtr << std::endl;
    return 0;
}