#include <iostream>
#include <vector>

bool checkValid(std::vector<std::vector<int>> &grid, const int &len, const int &currentMove, const int &row, const int &col, const int &lastMove)
{
    if (row >= len || row < 0 || col >= len || col < 0 || grid[row][col] != currentMove)
    {
        return false;
    }

    if (currentMove == lastMove)
    {
        return true;
    }

    bool ans1 = checkValid(grid, len, currentMove + 1, row - 1, col - 2, lastMove);
    bool ans8 = checkValid(grid, len, currentMove + 1, row - 1, col + 2, lastMove);
    bool ans2 = checkValid(grid, len, currentMove + 1, row - 2, col - 1, lastMove);
    bool ans3 = checkValid(grid, len, currentMove + 1, row - 2, col + 1, lastMove);
    bool ans5 = checkValid(grid, len, currentMove + 1, row + 1, col - 2, lastMove);
    bool ans4 = checkValid(grid, len, currentMove + 1, row + 1, col + 2, lastMove);
    bool ans7 = checkValid(grid, len, currentMove + 1, row + 2, col - 1, lastMove);
    bool ans6 = checkValid(grid, len, currentMove + 1, row + 2, col + 1, lastMove);

    return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
}

bool checkValidGrid(std::vector<std::vector<int>> &grid)
{
    int len = grid.size();
    int lastMove = len * len - 1;
    return checkValid(grid, len, 0, 0, 0, lastMove);
}

int main()
{
    std::vector<std::vector<int>> grid = {{0, 11, 16, 5, 20},
                                          {17, 4, 19, 10, 15},
                                          {12, 1, 8, 21, 6},
                                          {3, 18, 23, 14, 9},
                                          {24, 13, 2, 7, 22}};

    std::cout << checkValidGrid(grid) << std::endl;

    return 0;
}