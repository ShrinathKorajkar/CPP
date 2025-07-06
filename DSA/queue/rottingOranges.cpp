#include <iostream>
#include <vector>
#include <queue>

/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
*/

int orangesRotting(std::vector<std::vector<int>> &grid)
{
    int rowSize = grid.size();
    int colSize = grid[0].size();

    std::vector<std::vector<int>> visited(rowSize, std::vector<int>(colSize, 0));
    std::queue<std::pair<int, int>> queue;

    int rottenCount = 0;
    int freshCount = 0;

    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            if (grid[i][j] == 1)
            {
                freshCount++;
            }
            else if (grid[i][j] == 2)
            {
                visited[i][j] = 1;
                queue.emplace(i, j);
            }
        }
    }

    if (freshCount == 0)
    {
        return 0;
    }

    int minutes = 0;

    while (!queue.empty())
    {
        minutes++;
        rottenCount = queue.size();
        for (int i = 0; i < rottenCount; i++)
        {
            auto pair = queue.front();
            int j = pair.first, k = pair.second;
            queue.pop();

            if (j - 1 >= 0 && visited[j - 1][k] == 0 && grid[j - 1][k] == 1)
            {
                visited[j - 1][k] = 1;
                freshCount--;
                queue.emplace(j - 1, k);
            }

            if (j + 1 < rowSize && visited[j + 1][k] == 0 && grid[j + 1][k] == 1)
            {
                visited[j + 1][k] = 1;
                freshCount--;
                queue.emplace(j + 1, k);
            }

            if (k - 1 >= 0 && visited[j][k - 1] == 0 && grid[j][k - 1] == 1)
            {
                visited[j][k - 1] = 1;
                freshCount--;
                queue.emplace(j, k - 1);
            }

            if (k + 1 < colSize && visited[j][k + 1] == 0 && grid[j][k + 1] == 1)
            {
                visited[j][k + 1] = 1;
                freshCount--;
                queue.emplace(j, k + 1);
            }
        }

        if (freshCount == 0)
        {
            return minutes;
        }
    }

    return -1;
}

int main()
{
    std::vector<std::vector<int>> grid = {{1, 2}};

    std::cout << orangesRotting(grid) << std::endl;
    return 0;
}