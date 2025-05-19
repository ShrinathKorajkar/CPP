#include <iostream>
#include <vector>

/*
    TC: - (9 ^ emptySpace)
*/

bool isSafeToPlace(std::vector<std::vector<char>> &suduku, int row, int col, char val)
{
    // Row and Col
    for (int i = 0; i < 9; i++)
    {
        if (suduku[row][i] == val || suduku[i][col] == val)
        {
            return false;
        }
    }

    // Grid
    int gridStartRow = (row / 3) * 3;
    int gridStartCol = (col / 3) * 3;
    for (int i = gridStartRow; i <= gridStartRow + 2; i++)
    {
        for (int j = gridStartCol; j <= gridStartCol + 2; j++)
        {
            if (suduku[i][j] == val)
            {
                return false;
            }
        }
    }

    return true;
}

bool sudukuHelper(std::vector<std::vector<char>> &suduku, int row, int col)
{
    if (row == 9)
    {
        return true;
    }

    int nextRow = row, nextCol = col + 1;
    if (nextCol == 9)
    {
        nextRow++;
        nextCol = 0;
    }

    if (suduku[row][col] != '.')
    {
        return sudukuHelper(suduku, nextRow, nextCol);
    }

    for (int i = 1; i < 10; i++)
    {
        if (isSafeToPlace(suduku, row, col, '0' + i))
        {
            suduku[row][col] = '0' + i;
            if (sudukuHelper(suduku, nextRow, nextCol))
            {
                return true;
            }
            suduku[row][col] = '.';
        }
    }

    return false;
}

bool solveSuduku(std::vector<std::vector<char>> &suduku)
{
    return sudukuHelper(suduku, 0, 0);
}

int main()
{
    std::vector<std::vector<char>> suduku = {
        {'2', '.', '.', '.', '.', '1', '4', '.', '.'},
        {'7', '.', '.', '.', '9', '.', '.', '.', '.'},
        {'.', '3', '.', '.', '5', '6', '.', '.', '2'},
        {'.', '7', '.', '2', '1', '8', '5', '.', '6'},
        {'1', '.', '2', '.', '.', '5', '9', '3', '.'},
        {'.', '6', '.', '.', '.', '9', '.', '.', '.'},
        {'6', '.', '.', '.', '8', '.', '.', '.', '.'},
        {'9', '.', '.', '5', '.', '3', '8', '.', '.'},
        {'4', '1', '8', '.', '2', '.', '.', '6', '5'}};

    if (solveSuduku(suduku))
    {
        for (auto row : suduku)
        {
            for (auto col : row)
            {
                std::cout << col << " ";
            }
            std::cout << std::endl;
        }
    }
    return 0;
}
