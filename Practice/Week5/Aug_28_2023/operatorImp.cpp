#include <iostream>
#include <stdexcept>

class test
{
    int a;

public:
    explicit test(const int &a = 10) : a(a) {}
    test(const test &other) : a(other.a) {}

    test &operator=(const test &other)
    {
        if (this == &other)
            return *this;

        a = other.a;
        return *this;
    }

    test &operator=(test &&other) noexcept
    {
        if (this == &other)
            return *this;

        a = other.a;
        other.a = 0; // leave moved-from object in valid state
        return *this;
    }

    bool operator==(const test &rhs) const
    {
        return a == rhs.a;
    }

    bool operator<(const test &rhs) const
    {
        return a < rhs.a;
    }

    friend std::ostream &operator<<(std::ostream &os, const test &t)
    {
        os << "test{a=" << t.a << "}";
        return os;
    }

    int &operator[](size_t idx)
    {
        if (idx != 0)
            throw std::out_of_range("test supports only index 0");
        return a;
    }

    const int &operator[](size_t idx) const
    {
        if (idx != 0)
            throw std::out_of_range("test supports only index 0");
        return a;
    }

    test &operator++()
    {
        ++a;
        return *this;
    }

    test operator++(int)
    {
        test temp(*this); // copy old value
        ++a;
        return temp;
    }

    void operator()(int x)
    {
        a += x;
    }

    explicit operator bool() const
    {
        return a != 0;
    }
};

int main()
{
    test t(5);

    ++t;
    t(10);

    std::cout << t << "\n";    // test{a=16}
    std::cout << t[0] << "\n"; // 16

    if (t)
        std::cout << "Valid\n";
}
