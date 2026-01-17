#include <iostream>
#include <unordered_set>
#include <numeric>
#include <vector>

int main()
{
    std::vector<int> arr = {1, 3, 4, 5};

    int ans = std::accumulate(arr.begin(), arr.begin() + 3, 0);

    std::cout << ans << std::endl;

    return 0;
}