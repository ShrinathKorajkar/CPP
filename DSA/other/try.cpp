#include <iostream>

void printWrong(int **arr)
{
    std::cout << "Trying arr[1][2] = " << arr[1][2] << "\n"; // 💣 UB
}

int main()
{
    int a[3][4] = {0};
    a[1][2] = 42;

    std::cout << "a[1][2] = " << a[1][2] << "\n";
    std::cout << "Casting to int** and accessing...\n";

    printWrong((int **)a); // ❌ Will print garbage or crash

    /*
        int* rows[3];
        rows[0] = new int[4];
        rows[1] = new int[4];
        rows[2] = new int[4];
        int** p = rows;        // Works

        the above code in memory:
        arr
        ├──> pointer
        │     ├──> pointer
        │     │     ├──> int
        │     │     ├──> int
        │     │     └──> ...
        │     └──> pointer
        └──> ...

        the arr[][] decays to int (*)[4]   // pointer to array of 4 int
        arr: [ int int int int ][ int int int int ][ int int int int ]
    */
    return 0;
}
