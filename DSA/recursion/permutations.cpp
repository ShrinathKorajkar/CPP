#include <iostream>
#include <vector>

void getPerms(std::vector<int> &nums, std::vector<std::vector<int>> &ans, int idx)
{
    if (idx == nums.size())
    {
        ans.emplace_back(nums);
        return;
    }
    for (int i = idx; i < nums.size(); i++)
    {
        std::swap(nums[idx], nums[i]);
        getPerms(nums, ans, idx + 1);
        std::swap(nums[idx], nums[i]);
    }
}

std::vector<std::vector<int>> permute(std::vector<int> &nums)
{
    std::vector<std::vector<int>> allperms;
    getPerms(nums, allperms, 0);
    return allperms;
}

int main()
{
    return 0;
}