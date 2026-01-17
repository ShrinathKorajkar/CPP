#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
/*
    The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.
    You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
    For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2.
    If there is no next greater element, then the answer for this query is -1.
    Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.
*/
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