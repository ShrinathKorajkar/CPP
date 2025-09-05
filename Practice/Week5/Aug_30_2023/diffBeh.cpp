#include <iostream>
using namespace std;

class CustomMemoryClass
{
public:
    int value;

    CustomMemoryClass(int val) : value(val)
    {
        cout << "Constructor called" << endl;
    }

    ~CustomMemoryClass()
    {
        cout << "Destructor called" << endl;
    }

    void *operator new(size_t size)
    {
        cout << "Custom new operator called" << endl;
        // std::cout << "No this pointer present inside new as no obj created yet";
        // std::cout << "compiler implicitly make new and delete as static " << this->value << std::endl; // Error
        void *memory = malloc(size);
        return memory;
    }

    void operator delete(void *memory)
    {
        cout << "Custom delete operator called" << endl;
        free(memory);
    }
};

int main()
{
    CustomMemoryClass *obj = new CustomMemoryClass(42);
    delete obj;

    return 0;
}
