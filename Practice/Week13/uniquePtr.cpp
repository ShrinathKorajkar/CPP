#include <iostream>

template <typename T>
class UniquePtr
{
    T *ptr;

public:
    // constructor
    explicit UniquePtr(T *p = nullptr) : ptr(p) {}

    // no copy
    UniquePtr(const UniquePtr &) = delete;
    UniquePtr &operator=(const UniquePtr &) = delete;

    // move
    UniquePtr(UniquePtr &&other) noexcept : ptr(other.ptr)
    {
        other.ptr = nullptr;
    }

    UniquePtr &operator=(UniquePtr &&other) noexcept
    {
        if (this != &other)
        {
            delete ptr;      // delete existing
            ptr = other.ptr; // take over
            other.ptr = nullptr;
        }
        return *this;
    }

    // destructor
    ~UniquePtr()
    {
        delete ptr;
    }

    // operators
    T &operator*() const { return *ptr; }
    T *operator->() const { return ptr; }
    T *get() const { return ptr; }
    explicit operator bool() const { return ptr != nullptr; }

    // release and reset
    T *release()
    {
        T *old = ptr;
        ptr = nullptr;
        return old;
    }

    void reset(T *p = nullptr)
    {
        delete ptr;
        ptr = p;
    }
};

int main()
{
    UniquePtr<int> p(new int(5));
    std::cout << *p; // 5

    UniquePtr<int> q = std::move(p);
    std::cout << *q; // 5

    return 0;
}
