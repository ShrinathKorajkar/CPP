#include <bits/stdc++.h>
using namespace std;
/*
    Find Kth largest/smallest
*/
// Partition function (like in QuickSort)
int partition(vector<int> &arr, int left, int right)
{
    int pivot = arr[right];
    int i = left;

    for (int j = left; j < right; j++)
    {
        if (arr[j] <= pivot)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[right]);
    return i; // pivot index
}

// Quickselect function
int quickSelect(vector<int> &arr, int left, int right, int k)
{
    if (left == right)
        return arr[left];

    int pivotIndex = partition(arr, left, right);

    if (pivotIndex == k)
        return arr[pivotIndex];
    else if (pivotIndex > k)
        return quickSelect(arr, left, pivotIndex - 1, k);
    else
        return quickSelect(arr, pivotIndex + 1, right, k);
}

int main()
{
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;

    // Find kth smallest
    int kthSmallest = quickSelect(arr, 0, arr.size() - 1, k - 1);
    cout << k << "rd smallest element: " << kthSmallest << endl;

    // Find kth largest → convert to kth smallest
    int n = arr.size();
    int kthLargest = quickSelect(arr, 0, n - 1, n - k);
    cout << k << "rd largest element: " << kthLargest << endl;

    return 0;
}
