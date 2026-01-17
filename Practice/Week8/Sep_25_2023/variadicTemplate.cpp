#include <iostream>

template <typename... Args> // 0 or more arguments
void printArgs(Args... arg)
{
    ((std::cout << arg << " "), ...); // expansion
    std::cout << std::endl;
}

// RECURSION
// Base case
int sum()
{
    return 0;
}

// Recursive case, fold expression C++17
template <typename First, typename... Rest>
int sum(First first, Rest... rest)
{
    return first + sum(rest...); // return (arg + ...); with only one param
}

// C++20 - constraints
// template <std::integral T>
// T multiply(T a, T b)
// {
//     return a * b;
// }

int main()
{
    int result = sum(1, 2, 3, 4, 5);
    std::cout << result << std::endl;

    printArgs(1, "hello", 2.33, '#');

    // cout << multiply(3, 4) << endl; // OK
    // cout << multiply(3.2, 4.5);     // Error: not integral

    return 0;
}