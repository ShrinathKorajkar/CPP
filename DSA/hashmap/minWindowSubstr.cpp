#include <iostream>
#include <unordered_map>

/*
    Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t
    (including duplicates) is included in the window. If there is no such substring, return the empty string "".
    answer is unique.

    Example:
    Input: s = "ADOBECODEBANC", t = "ABC"
    Output: "BANC"
    Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
*/

std::string minWindow(std::string s, std::string t)
{
    int map[128] = {0};
    std::string ans = "";
    int start = 0, end = 0;
    int distance = INT_MAX;
    int head = 0;
    int count = t.size();

    for (auto ch : t)
    {
        map[ch]++;
    }

    while (end < s.size())
    {
        if (map[s[end]] > 0)
        {
            count--;
        }
        map[s[end]]--;
        end++;

        while (count == 0)
        {
            int newDist = end - start;
            if (newDist < distance)
            {
                distance = newDist;
                head = start;
            }

            if (map[s[start]] == 0)
            {
                count++;
            }

            map[s[start]]++;
            start++;
        }
    }

    if (distance != INT_MAX)
    {
        ans = s.substr(head, distance);
    }

    return ans;
}

int main()
{
    std::string s = "ADOBECODEBANC";
    std::string t = "ABC";
    std::cout << minWindow(s, t) << std::endl;

    return 0;
}