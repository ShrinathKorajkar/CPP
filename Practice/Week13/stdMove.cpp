#include <iostream>
#include <utility>
/*
    https://0xghost.dev/blog/std-move-deep-dive/
*/
class Resource
{
private:
    int *data;
    size_t size;

public:
    // Constructor
    Resource(size_t n) : data(new int[n]), size(n)
    {
        std::cout << "Constructing Resource with " << n << " elements\n";
    }

    // Destructor
    ~Resource()
    {
        std::cout << "Destroying Resource\n";
        delete[] data;
    }

    // Copy constructor: creates a deep copy
    Resource(const Resource &other)
        : data(new int[other.size]), size(other.size)
    {
        std::cout << "Copy constructing Resource\n";
        std::copy(other.data, other.data + size, data);
    }

    // Copy assignment operator: creates a deep copy
    Resource &operator=(const Resource &other)
    {
        std::cout << "Copy assigning Resource\n";
        if (this != &other)
        { // Protect against self-assignment
            // Allocate into a TEMPORARY pointer first.
            int *new_data = new int[other.size];
            std::copy(other.data, other.data + other.size, new_data);
            delete[] data;
            // Update the state
            data = new_data;
            size = other.size;
        }
        return *this;
    }

    // Move constructor: transfers ownership
    Resource(Resource &&other) noexcept
        : data(std::exchange(other.data, nullptr)),
          size(std::exchange(other.size, 0))
    {
        std::cout << "Move constructing Resource\n";
    }

    // Move assignment operator: transfers ownership
    Resource &operator=(Resource &&other) noexcept
    {
        std::cout << "Move assigning Resource\n";
        if (this != &other)
        { // Protect against self-assignment
            delete[] data;
            data = std::exchange(other.data, nullptr);
            size = std::exchange(other.size, 0);
        }
        return *this;
    }
};