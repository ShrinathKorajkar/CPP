#include <iostream>
#include <string>

template <typename T>
std::string returnStr(const T &value)
{
    return std::to_string(value);
}

template <typename T>
std::string returnStr(const T *value)
{
    return value;
}

template <> // specialization
std::string returnStr(const char &value)
{
    return std::string(1, value);
}

template <typename T, typename U>
void print(const T &value, const U &value1)
{
    std::cout << value << std::endl;
    std::cout << value1 << std::endl;
}

template <typename Container>
void print_first(Container c)
{
    typename Container::iterator it = c.begin(); // must use typename or else compiler will think iterator is a static var not a type
    std::cout << *it << std::endl;
}

int main()
{
    std::cout << returnStr(1) << std::endl;
    std::cout << returnStr(1.1) << std::endl;
    std::cout << returnStr('@') << std::endl;
    std::cout << returnStr('a') << std::endl;
    std::cout << returnStr(true) << std::endl;
    std::cout << returnStr("false") << std::endl;
    return 0;
}