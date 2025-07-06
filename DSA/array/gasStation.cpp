#include <iostream>
#include <vector>

int canCompleteCircuit(std::vector<int> &gas, std::vector<int> &cost)
{
    int sumGas = 0, sumCost = 0;
    for (int i = 0; i < gas.size(); i++)
    {
        sumGas += gas[i];
        sumCost += cost[i];
    }

    if (sumGas < sumCost)
    {
        return -1;
    }

    int ans = 0;
    int remGas = 0;

    for (int i = 0; i < gas.size(); i++)
    {
        remGas += gas[i] - cost[i];
        if (remGas < 0)
        {
            remGas = 0;
            ans = i + 1;
        }
    }

    return ans;
}

int main()
{
    std::vector<int> gas = {1, 2, 3, 4, 5};
    std::vector<int> cost = {3, 4, 5, 1, 2};
    std::cout << canCompleteCircuit(gas, cost);

    return 0;
}