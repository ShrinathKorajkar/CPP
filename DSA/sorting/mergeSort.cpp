#include <iostream>
#include <vector>

void merge(std::vector<int> &arr, int start, int mid, int end)
{
    std::vector<int> temp;
    int i = start, j = mid + 1;
    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            temp.push_back(arr[i++]);
        }
        else
        {
            temp.push_back(arr[j++]);
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i++]);
    }

    while (j <= end)
    {
        temp.push_back(arr[j++]);
    }

    for (i = start; i <= end; i++)
    {
        arr[i] = temp[i - start];
    }
}

void mSort(std::vector<int> &arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int mid = start + (end - start) / 2;
    mSort(arr, start, mid);
    mSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

void mergeSort(std::vector<int> &arr)
{
    mSort(arr, 0, arr.size() - 1);
}

int main()
{
    std::vector<int> arr = {3, 4, 5, 1, 5, 8, 0, 3, 7};
    mergeSort(arr);
    for (auto val : arr)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
