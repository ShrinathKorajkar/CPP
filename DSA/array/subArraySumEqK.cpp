#include <iostream>
#include <vector>
#include <unordered_map>

int subarraySum(std::vector<int> &nums, int k)
{
    int len = nums.size();
    int sum = 0;
    int noOfSubArrays = 0;
    std::unordered_map<int, int> map(len);

    for (int i = 0; i < len; i++)
    {
        sum += nums[i];
        if (sum == k)
        {
            noOfSubArrays++;
        }

        if (map.find(sum - k) != map.end())
        {
            noOfSubArrays += map[sum - k];
        }

        if (map.find(sum) == map.end())
        {
            map[sum] = 0;
        }
        map[sum]++;
    }

    return noOfSubArrays;
}

int main()
{
    return 0;
}