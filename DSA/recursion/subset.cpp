#include <iostream>
#include <vector>

/*
    TC: 2^N * N
*/
void allSubsetsUtil(const std::vector<int> &arr, std::vector<int> &choice, int i)
{
    if (i == arr.size())
    {
        std::cout << "{";
        for (int elem : choice)
        {
            std::cout << elem << ",";
        }
        std::cout << "}" << std::endl;
        return;
    }

    choice.push_back(arr[i]);
    allSubsetsUtil(arr, choice, i + 1);
    choice.pop_back();
    /*
        For removing duplicate sets
        1. sort the array before
        2. idx = i + 1
        3. while(idx < arr.size() && arr[idx] == arr[idx - 1]) idx++;
        4. allSubsetsUtil(arr, choice, idx)
    */
    allSubsetsUtil(arr, choice, i + 1);
}

void printAllSubsets(const std::vector<int> &arr)
{
    std::vector<int> choice;
    allSubsetsUtil(arr, choice, 0);
}

int main()
{
    std::vector<int> arr = {1, 2, 3, 4};
    printAllSubsets(arr);
    return 0;
}