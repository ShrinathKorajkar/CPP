#include <iostream>
#include <vector>
using namespace std;

// Partition function
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high]; // choose last element as pivot
    int i = low - 1;       // index of smaller element

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]); // place smaller element on left side
        }
    }

    // place pivot in correct position
    swap(arr[i + 1], arr[high]);
    return i + 1; // return pivot index
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
