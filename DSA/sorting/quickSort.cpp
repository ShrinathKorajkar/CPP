#include <iostream>
#include <vector>
using namespace std;

/*
    Pivot Selection:
    1. First element / Last element -> worst case on sorted arrays (not recommended, use only in interviews as simple)
    2. Middle element -> works well for partial sorted
    3. Random pivot -> avoid worst case patterns, very good avg performance (recommended)
    4. Median of three -> median of first, middle, last element, reduces recusion depth, close to optimal (best, used in many std libs), used by std::sort()
*/

// Partition function
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high]; // choose last element as pivot
    int i = low;           // index of smaller element

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            swap(arr[i], arr[j]); // place smaller element on left side
            i++;
        }
    }

    // place pivot in correct position
    swap(arr[i], arr[high]);
    return i; // return pivot index
}

// Quicksort
void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        // Recursively sort left and right
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    vector<int> arr = {7, 2, 1, 6, 8, 5, 3, 4};

    quickSort(arr, 0, arr.size() - 1);

    for (int x : arr)
        cout << x << " ";

    return 0;
}
