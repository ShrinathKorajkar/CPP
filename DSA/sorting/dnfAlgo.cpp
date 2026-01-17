#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
    *Dutch National Flag Algorithm
    Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects
    of the same color are adjacent, with the colors in the order red, white, and blue.
    We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
    Input: nums = [2,0,2,1,1,0]
    Output: [0,0,1,1,2,2]
*/

void sortColors(vector<int> &nums)
{
    int red = 0;
    int white = 0;
    int blue = nums.size() - 1;
    while (white <= blue)
    {
        if (nums[white] == 0)
        {
            std::swap(nums[red], nums[white]);
            white++;
            red++;
        }
        else if (nums[white] == 2)
        {
            std::swap(nums[white], nums[blue]);
            blue--;
        }
        else
        {
            white++;
        }
    }
}

int main()
{

    return 0;
}