#include <iostream>
#include <vector>
#include <stack>

int largestRectangleArea(std::vector<int> &heights)
{
    int len = heights.size();
    std::stack<int> stack;
    std::vector<int> rightSmall(len, 0);
    std::vector<int> leftSmall(len, 0);

    for (int i = len - 1; i >= 0; i--)
    {
        while (!stack.empty() && heights[stack.top()] >= heights[i])
        {
            stack.pop();
        }

        rightSmall[i] = stack.empty() ? len : stack.top();
        stack.push(i);
    }

    while (!stack.empty())
    {
        stack.pop();
    }

    for (int i = 0; i < len; i++)
    {
        while (!stack.empty() && heights[stack.top()] >= heights[i])
        {
            stack.pop();
        }

        leftSmall[i] = stack.empty() ? -1 : stack.top();
        stack.push(i);
    }

    int ans = 0;

    for (int i = 0; i < len; i++)
    {
        int width = rightSmall[i] - leftSmall[i] - 1;
        ans = std::max(ans, heights[i] * width);
    }

    return ans;
}

int main()
{

    return 0;
}