#include <iostream>
#include <vector>
#include <stack>

/*
The min-product of an array is equal to the minimum value in the array multiplied by the array's sum.

For example, the array [3,2,5] (minimum value is 2) has a min-product of 2 * (3+2+5) = 2 * 10 = 20.
Given an array of integers nums, return the maximum min-product of any non-empty subarray of nums.
*/

int maxSumMinProduct(std::vector<int> &nums)
{
    int size = nums.size();
    std::stack<int> stack;
    std::vector<long> prefixSum(size + 1, 0);
    long ans = 0;

    for (int i = 0; i < size; i++)
    {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }

    for (int i = 0; i < size + 1; i++)
    {
        while (!stack.empty() && (i == size || nums[stack.top()] > nums[i]))
        {
            int j = stack.top();
            stack.pop();

            int min = nums[j];
            j = stack.empty() ? 0 : stack.top() + 1;

            long subArrProd = min * (prefixSum[i] - prefixSum[j]);
            ans = std::max(ans, subArrProd);
        }
        stack.push(i);
    }

    return ans % 1000000007;
}

int main()
{
    std::vector<std::vector<int>> nums = {{3, 2, 5},
                                          {1, 2, 3, 2},
                                          {2, 3, 3, 1, 2},
                                          {3, 1, 5, 6, 4, 2},
                                          {3},
                                          {3, 0}};

    for (auto num : nums)
    {
        std::cout << maxSumMinProduct(num) << std::endl;
    }

    return 0;
}