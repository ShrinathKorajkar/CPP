#include <iostream>
#include <vector>
#include <sstream>

int compareVersion(std::string version1, std::string version2)
{
    std::stringstream str1(version1);
    std::stringstream str2(version2);

    std::vector<int> ver1, ver2;
    std::string rev;
    while (std::getline(str1, rev, '.'))
    {
        ver1.push_back(std::atoi(rev.c_str()));
    }

    while (std::getline(str2, rev, '.'))
    {
        ver2.push_back(std::atoi(rev.c_str()));
    }

    while (ver1.size() != ver2.size())
    {
        if (ver1.size() < ver2.size())
        {
            ver1.push_back(0);
        }
        else
        {
            ver2.push_back(0);
        }
    }

    for (int i = 0; i < ver1.size(); i++)
    {
        if (ver1[i] == ver2[i])
        {
            continue;
        }

        if (ver1[i] < ver2[i])
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }

    return 0;
}

int main()
{
    return 0;
}