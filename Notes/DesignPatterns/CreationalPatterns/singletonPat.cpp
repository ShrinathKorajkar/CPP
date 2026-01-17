#include <iostream>
#include <mutex>

/*
    Globlal point of access -> Resource managers, logging, configuration, caching, hardware access, global rendrer
    Singleton Pattern  ->  Ensures that a class has only one instance and provides a global point of access to it.
                           This is useful when exactly one object is needed to coordinate actions across the system.
*/

// Thread safe - Singleton
class Singleton
{
    // static Singleton *instance;
    Singleton() = default;
    Singleton(const Singleton &other) = delete;
    Singleton &operator=(const Singleton &other) = delete;
    Singleton(Singleton &&other) = delete;
    Singleton &operator=(Singleton &&other) = delete;
    // ~Singleton() { delete instance; }

    std::mutex mtx;

public:
    static Singleton &getInstance()
    {
        static Singleton instance;
        return instance;
        // if (instance == nullptr)
        // {
        //     instance = new Singleton();
        // }
        // return *instance;
    }

    void log(const std::string &msg)
    {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "[LOG]: " << msg << std::endl;
    }
};

// Singleton *Singleton::instance = nullptr;

int main()
{
    Singleton &ref1 = Singleton::getInstance();
    Singleton &ref2 = Singleton::getInstance();

    if (&ref1 == &ref2)
    {
        std::cout << "ref1 and ref2 are same instance" << std::endl;
    }
    else
    {
        std::cout << "ref1 and ref2 are different instance" << std::endl;
    }
    return 0;
}