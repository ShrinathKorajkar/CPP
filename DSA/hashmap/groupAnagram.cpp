#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
/*
    Counting Sort can increase the time complexity

    string strSort(string s) {
        int counter[26] = {0};
        for (char c : s) {
            counter[c - 'a']++;
        }
        string t;
        for (int c = 0; c < 26; c++) {
            t += string(counter[c], c + 'a');
        }
        return t;
    }
*/

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
    std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    std::vector<std::vector<std::string>> ans = groupAnagrams(strs);

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