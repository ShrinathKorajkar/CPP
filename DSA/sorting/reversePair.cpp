#include <iostream>
#include <vector>

int merge(std::vector<int> &nums, int start, int mid, int end)
{
    int reversePairs = 0;
    std::vector<int> temp;
    int i = start, j = mid + 1;

    int ed = mid + 1;
    for (int st = start; st <= mid; st++)
    {
        while (ed <= end && (long long)nums[st] > 2LL * nums[ed])
        {
            ed++;
        }
        reversePairs += ed - (mid + 1);
    }

    while (i <= mid && j <= end)
    {
        if (nums[i] <= nums[j])
        {
            temp.push_back(nums[i]);
            i++;
        }
        else
        {
            temp.push_back(nums[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(nums[i++]);
    }

    while (j <= end)
    {
        temp.push_back(nums[j++]);
    }

    for (int k = start; k <= end; k++)
    {
        nums[k] = temp[k - start];
    }

    return reversePairs;
}

int mergeSort(std::vector<int> &nums, int start, int end)
{
    if (start >= end)
    {
        return 0;
    }

    int mid = start + (end - start) / 2;
    int pairCount1 = mergeSort(nums, start, mid);
    int pairCount2 = mergeSort(nums, mid + 1, end);
    int pairCount3 = merge(nums, start, mid, end);

    return pairCount1 + pairCount2 + pairCount3;
}

int reversePairs(std::vector<int> &nums)
{
    return mergeSort(nums, 0, nums.size() - 1);
}

int main()
{
    std::vector<int> nums = {1, 3, 2, 3, 1};
    std::cout << reversePairs(nums);

    return 0;
}