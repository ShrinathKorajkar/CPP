#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals)
{
    std::vector<std::vector<int>> ans;
    std::sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b)
              { return a[0] < b[0]; });
    for (int i = 0, j = 0; i < intervals.size();)
    {
        int second = intervals[i][1];

        while (j < intervals.size() - 1 && second >= intervals[j + 1][0])
        {
            j++;
            second = second > intervals[j][1] ? second : intervals[j][1];
        }

        std::vector<int> interval;
        interval.push_back(intervals[i][0]);
        interval.push_back(second);
        ans.emplace_back(interval);
        j++;
        i = j;
    }

    return ans;
}

int main()
{
    std::vector<std::vector<int>> intervals = {{1, 4}, {0, 2}, {3, 5}};
    std::vector<std::vector<int>> ans = merge(intervals);

    for (auto row : ans)
    {
        for (auto col : row)
        {
            std::cout << col << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return 0;
}