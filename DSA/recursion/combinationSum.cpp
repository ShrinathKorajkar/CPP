#include <iostream>
#include <vector>
#include <algorithm>

bool combinationSumHelper(std::vector<int> &candidates, int target, const int &len,
                          std::vector<std::vector<int>> &ans, std::vector<int> currentCombination, int index)
{
    if (0 > target)
    {
        return true;
    }

    if (0 == target)
    {
        ans.emplace_back(currentCombination);
        return true;
    }

    for (int i = index; i < len; i++)
    {
        currentCombination.push_back(candidates[i]);

        /* Uncomment if candidates must be used only once */
        // if (combinationSumHelper(candidates, target - candidates[i], len, ans, currentCombination, i + 1))
        if (combinationSumHelper(candidates, target - candidates[i], len, ans, currentCombination, i))
        {
            break;
        }

        /* Uncomment if candidates are not distinct and contain duplicates */
        // while (i < len - 1 && candidates[i] == candidates[i + 1])
        // {
        //     i++;
        // }

        currentCombination.pop_back();
    }

    return false;
}

std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target)
{
    int len = candidates.size();
    std::sort(candidates.begin(), candidates.end());
    std::vector<std::vector<int>> ans;
    std::vector<int> currentCombination;
    combinationSumHelper(candidates, target, len, ans, currentCombination, 0);
    return ans;
}

int main()
{
    std::vector<int> candidates = {2, 3, 5};
    std::vector<std::vector<int>> ans = combinationSum(candidates, 8);
    for (auto row : ans)
    {
        for (auto col : row)
        {
            std::cout << col << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}