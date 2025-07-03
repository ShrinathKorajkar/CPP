#include <iostream>
#include <vector>
#include <stack>

std::vector<int> nextGreaterElements(std::vector<int> &nums)
{
    std::vector<int> result(nums.size(), -1);

    std::stack<int> stack;
    for (int i = 0; i < nums.size() * 2; i++)
    {
        int num = nums[i % nums.size()];
        while (!stack.empty() && nums[stack.top()] < num)
        {
            result[stack.top()] = num;
            stack.pop();
        }

        if (i < nums.size())
        {
            stack.push(i);
        }
    }

    return result;
}

int main()
{

    return 0;
}