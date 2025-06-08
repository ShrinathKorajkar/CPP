#include <iostream>
#include <vector>

int trap(std::vector<int> &height)
{
    int len = height.size();
    std::vector<int> prefix(len);
    std::vector<int> suffix(len);
    long sum = 0;
    prefix[0] = height[0];
    suffix[len - 1] = height[len - 1];

    for (int i = 1; i < len; i++)
    {
        prefix[i] = std::max(prefix[i - 1], height[i]);
        suffix[len - i - 1] = std::max(suffix[len - i], height[len - i - 1]);
    }

    for (int i = 1; i < len - 1; i++)
    {
        sum += std::min(prefix[i], suffix[i]) - height[i];
    }

    return sum;
}

int trap2(std::vector<int> &height)
{
    int len = height.size();
    int sum = 0;
    int left = 0;
    int right = len - 1;
    int leftMost = height[0];
    int rightMost = height[len - 1];

    while (left <= right)
    {
        leftMost = std::max(leftMost, height[left]);
        rightMost = std::max(rightMost, height[right]);

        int min = std::min(leftMost, rightMost);
        if (min == leftMost)
        {
            sum += min - height[left];
            left++;
        }
        else
        {
            sum += min - height[right];
            right--;
        }
    }

    return sum;
}

int main()
{
    std::vector<int> height = {4, 2, 0, 3, 2, 5};
    std::cout << trap2(height) << std::endl;

    return 0;
}