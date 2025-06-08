#include <iostream>
#include <vector>
#include <list>
#include <deque>

void printWindow(std::list<int> &window)
{
    for (auto num : window)
    {
        std::cout << num << ";";
    }
    std::cout << std::endl;
}

std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k)
{
    std::vector<int> slidingWindow;
    // std::list<int> list(k);  // takes 100ms
    std::deque<int> list(k); // takes 22ms

    for (int i = 0; i < k; i++)
    {
        while (!list.empty() && list.back() < nums[i])
        {
            list.pop_back();
        }
        list.push_back(nums[i]);
    }

    slidingWindow.push_back(list.front());

    for (int i = k; i < nums.size(); i++)
    {
        if (list.front() == nums[i - k])
        {
            list.pop_front();
        }

        while (!list.empty() && list.back() < nums[i])
        {
            list.pop_back();
        }

        list.push_back(nums[i]);
        // printWindow(list);
        slidingWindow.push_back(list.front());
    }

    return slidingWindow;
}

int main()
{
    std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    std::vector<int> ans = maxSlidingWindow(nums, k);
    for (int i = 0; i < ans.size(); i++)
    {
        std::cout << ans[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}