#include <iostream>
#include <vector>

bool isPalindrome(std::string str)
{
    for (int i = 0, j = str.length() - 1; i < j; i++, j--)
    {
        if (str[i] != str[j])
        {
            return false;
        }
    }
    return true;
}

void doPartition(std::string s, const int &len, std::vector<std::vector<std::string>> &ans, std::vector<std::string> currentPartition, int index)
{
    if (index == len)
    {
        ans.emplace_back(currentPartition);
        return;
    }

    for (int i = index; i < len; i++)
    {
        std::string firstParitition = s.substr(index, i - index + 1);
        if (isPalindrome(firstParitition))
        {
            currentPartition.push_back(firstParitition);
            doPartition(s, len, ans, currentPartition, i + 1);
            currentPartition.pop_back();
        }
    }
}

std::vector<std::vector<std::string>> partition(std::string s)
{
    std::vector<std::vector<std::string>> ans;
    std::vector<std::string> currentPartition;
    doPartition(s, s.size(), ans, currentPartition, 0);
    return ans;
}

int main()
{
    std::string str = "abaabcaba";
    std::vector<std::vector<std::string>> ans = partition(str);
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