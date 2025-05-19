#include <iostream>
#include <vector>

int merge(std::vector<int> &arr, int start, int mid, int end)
{
    std::vector<int> temp;
    int i = start, j = mid + 1;
    int inversions = 0;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i++]);
        }
        else
        {
            temp.push_back(arr[j++]);
            inversions += mid - i + 1;
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

    return inversions;
}

int mSort(std::vector<int> &arr, int start, int end)
{
    if (start >= end)
    {
        return 0;
    }

    int mid = start + (end - start) / 2;
    int inversions1 = mSort(arr, start, mid);
    int inversions2 = mSort(arr, mid + 1, end);
    int inversions3 = merge(arr, start, mid, end);

    return inversions1 + inversions2 + inversions3;
}

int countInversions(std::vector<int> &arr)
{
    return mSort(arr, 0, arr.size() - 1);
}

int main()
{
    // std::vector<int> arr = {3, 4, 5, 1, 5, 8, 0, 3, 7};
    std::vector<int> arr = {6, 3, 3, 5, 2, 7};
    int inversions = countInversions(arr);
    std::cout << inversions << std::endl;

    return 0;
}
