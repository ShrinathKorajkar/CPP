// #include "test.h"
#include <iostream>

int main()
{
    int a = 10;
    int b = a++ + a++ + a++;
    // int c = a;
    std::cout << b << std::endl;
    return 0;
}
