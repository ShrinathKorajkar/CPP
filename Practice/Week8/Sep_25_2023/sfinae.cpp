/*
SFINAE (Substitution Failure Is Not An Error)
*/
#include <type_traits>
#include <iostream>
using namespace std;

template <typename T>
auto print_if_integral(T val) -> typename enable_if<is_integral<T>::value>::type
{
    cout << val << " is integral\n";
}

template <typename T>
auto print_if_integral(T val) -> typename enable_if<!is_integral<T>::value>::type
{
    cout << val << " is not integral\n";
}

int main()
{
    print_if_integral(10);   // integral
    print_if_integral(3.14); // not integral
}
