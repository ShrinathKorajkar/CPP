#include <iostream>
#include <vector>
#include <algorithm>
/*
    Farmer John has built a new long barn, with N (2 ≤ N ≤ 100,000) stalls. The stalls are located along a straight
    line at positions x1 ... xN (0 ≤ xi ≤ 1,000,000,000).
    His C (2 ≤ C ≤ N) cows don't like this barn layout and become aggressive towards each other once put into a stall.
    To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum
    distance between any two of them is as large as possible. What is the largest minimum distance?
*/
bool isPossible(std::vector<int> stalls, int noOfCows, int minDistance)
{
    int cowsPlaced = 1;
    int lastPosition = stalls[0];
    for (int i = 1; i < stalls.size(); i++)
    {
        if (cowsPlaced == noOfCows)
        {
            return true;
        }
        if (stalls[i] - lastPosition >= minDistance)
        {
            cowsPlaced++;
            lastPosition = stalls[i];
        }
    }
    return false;
}

int maxDistance(std::vector<int> stalls, int noOfCows)
{
    int n = stalls.size();
    std::sort(stalls.begin(), stalls.end());

    int minDistance = 1;
    int maxDistance = stalls[n - 1] - stalls[0];
    int answer = -1;
    while (minDistance <= maxDistance)
    {
        int mid = minDistance + (maxDistance - minDistance) / 2;
        if (isPossible(stalls, noOfCows, mid))
        {
            minDistance = mid + 1;
            answer = mid;
        }
        else
        {
            maxDistance = mid - 1;
        }
    }
    return answer;
}

int main()
{
    std::vector<int> stalls = {1, 2, 8, 4, 9};
    std::cout << maxDistance(stalls, 3) << std::endl;

    return 0;
}