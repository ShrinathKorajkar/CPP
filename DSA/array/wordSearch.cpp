#include <iostream>
#include <vector>

bool searchWord(std::vector<std::vector<char>> &board, std::string word, int i, int j, int currIdx)
{
    if (currIdx >= word.size())
    {
        return true;
    }

    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[currIdx])
    {
        return false;
    }

    board[i][j] = '\0';

    if (searchWord(board, word, i - 1, j, currIdx + 1) ||
        searchWord(board, word, i, j + 1, currIdx + 1) ||
        searchWord(board, word, i + 1, j, currIdx + 1) ||
        searchWord(board, word, i, j - 1, currIdx + 1))
    {
        return true;
    }

    board[i][j] = word[currIdx];

    return false;
}

bool exist(std::vector<std::vector<char>> &board, std::string word)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (searchWord(board, word, i, j, 0))
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    std::vector<std::vector<char>> board = {{'A', 'B', 'C', 'E'},
                                            {'S', 'F', 'C', 'S'},
                                            {'A', 'D', 'E', 'E'}};
    std::string word = "ABCCED";
    std::cout << exist(board, word) << std::endl;

    return 0;
}