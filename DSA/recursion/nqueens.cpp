#include <iostream>
#include <vector>

bool safeToPlace(int n, std::vector<std::string> &board, int row, int col)
{
    // top
    for (int i = row - 1; i >= 0; i--)
    {
        if (board[i][col] == 'Q')
        {
            return false;
        }
    }

    // top-left
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }

    // top-right
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }

    return true;
}

void placeQueens(int n, std::vector<std::vector<std::string>> &ans, std::vector<std::string> &board, int row)
{
    if (row == n)
    {
        ans.emplace_back(board);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (safeToPlace(n, board, row, i))
        {
            board[row][i] = 'Q';
            placeQueens(n, ans, board, row + 1);
            board[row][i] = '.';
        }
    }
}

std::vector<std::vector<std::string>> solveNQueens(int n)
{
    std::vector<std::vector<std::string>> ans;
    std::vector<std::string> board;

    for (int i = 0; i < n; i++)
    {
        std::string row(n, '.');
        board.emplace_back(row);
    }

    placeQueens(n, ans, board, 0);

    return ans;
}

int main()
{
    std::vector<std::vector<std::string>> ans = solveNQueens(4);
    for (auto row : ans)
    {
        for (auto row2 : row)
        {
            std::cout << row2 << std::endl;
        }
    }
    return 0;
}