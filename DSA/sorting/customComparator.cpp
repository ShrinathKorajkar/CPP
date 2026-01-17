#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Item
{
    int key;
    std::string name;
};

bool compare(const Item &a, const Item &b)
{
    if (a.key != b.key)
        return a.key < b.key; // primary sort (int)
    return a.name < b.name;   // secondary sort (string)
}

int main()
{
    std::vector<Item> arr = {
        {2, "banana"},
        {1, "apple"},
        {2, "apple"},
        {1, "cherry"}};

    std::sort(arr.begin(), arr.end(), compare);
    return 0;
}
