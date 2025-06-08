#include <iostream>
#include <vector>

std::string longestCommonPrefix(std::vector<std::string> &strs)
{
    std::string res = strs[0];
    for (auto str : strs)
    {
        int i = 0;
        int j = 0;
        while (i < res.size() && str[j] == res[i])
        {
            i++;
            j++;
        }
        res = res.substr(0, i);
        if (res == "")
        {
            break;
        }
    }
    return res;
}

int main()
{

    return 0;
}