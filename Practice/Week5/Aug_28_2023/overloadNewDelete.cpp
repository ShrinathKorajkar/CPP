#include <iostream>
#include <cstdlib>
/*
Static → Because they don’t work on an object (you are trying to create/destroy the object itself, so there is no valid this yet).
*/
class MyClass
{
public:
    MyClass()
    {
        std::cout << "Constructor called\n";
    }

    ~MyClass()
    {
        std::cout << "Destructor called\n";
    }

    // Overload operator new
    static void *operator new(std::size_t size)
    {
        std::cout << "Custom operator new called with size: " << size << "\n";
        void *p = std::malloc(size);
        if (!p)
            throw std::bad_alloc();
        return p;
    }

    // Overload operator delete
    static void operator delete(void *p)
    {
        std::cout << "Custom operator delete called\n";
        std::free(p);
    }

    // Overload operator new[]
    static void *operator new[](std::size_t size)
    {
        std::cout << "Custom operator new[] called with size: " << size << "\n";
        void *p = std::malloc(size);
        if (!p)
            throw std::bad_alloc();
        return p;
    }

    // Overload operator delete[]
    static void operator delete[](void *p)
    {
        std::cout << "Custom operator delete[] called\n";
        std::free(p);
    }
};

int main()
{
    std::cout << "---- SINGLE OBJECT ----\n";
    MyClass *obj = new MyClass(); // Calls constructor
    delete obj;                   // Calls destructor

    std::cout << "---- ARRAY OF OBJECTS ----\n";
    MyClass *arr = new MyClass[3]; // Calls constructor 3 times
    delete[] arr;                  // Calls destructor 3 times
}
