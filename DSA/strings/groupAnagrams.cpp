#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs)
{
    std::vector<std::vector<std::string>> groups;
    std::unordered_map<std::string, std::vector<std::string>> map;

    for (auto str : strs)
    {
        std::string currStr = str;
        std::sort(currStr.begin(), currStr.end());
        map[currStr].push_back(str);
    }

    for (auto item : map)
    {
        groups.push_back(item.second);
    }

    return groups;
}

int main()
{
    std::vector<std::string> arr = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto ans = groupAnagrams(arr);

    for (auto groups : ans)
    {
        for (auto str : groups)
        {
            std::cout << str << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}