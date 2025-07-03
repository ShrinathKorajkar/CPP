#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

std::vector<int> nextGreaterElement(std::vector<int> &nums1, std::vector<int> &nums2)
{
    int len1 = nums1.size();
    int len2 = nums2.size();

    std::unordered_map<int, int> map;
    std::stack<int> greaterStack;

    for (int i = len2 - 1; i >= 0; i--)
    {
        while (!greaterStack.empty() && greaterStack.top() < nums2[i])
        {
            greaterStack.pop();
        }

        if (greaterStack.empty())
        {
            map[nums2[i]] = -1;
        }
        else
        {
            map[nums2[i]] = greaterStack.top();
        }

        greaterStack.push(nums2[i]);
    }

    std::vector<int> result;
    for (auto num : nums1)
    {
        result.push_back(map[num]);
    }

    return result;
}

int main()
{

    return 0;
}