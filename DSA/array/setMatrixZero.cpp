#include <iostream>
#include <vector>
/*
    Given an m x n integer matrix, if an element is 0, set its entire row and column to 0's.
    You must do it in place.
*/
void printMatrix(std::vector<std::vector<int>> &matrix)
{
    for (auto row : matrix)
    {
        for (auto col : row)
        {
            std::cout << col << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void setZeroes(std::vector<std::vector<int>> &matrix)
{
    int rowLen = matrix.size();
    int colLen = matrix[0].size();

    bool isColZero = false;
    bool isRowZero = false;

    for (int i = 0; i < rowLen; i++)
    {
        if (matrix[i][0] == 0)
        {
            isColZero = true;
            break;
        }
    }

    for (int i = 0; i < colLen; i++)
    {
        if (matrix[0][i] == 0)
        {
            isRowZero = true;
            break;
        }
    }

    for (int i = 1; i < rowLen; i++)
    {
        for (int j = 1; j < colLen; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = matrix[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < rowLen; i++)
    {
        for (int j = 1; j < colLen; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }

    if (isRowZero)
    {
        for (int i = 0; i < colLen; i++)
        {
            matrix[0][i] = 0;
        }
    }

    if (isColZero)
    {
        for (int i = 0; i < rowLen; i++)
        {
            matrix[i][0] = 0;
        }
    }
}

int main()
{
    // std::vector<std::vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    std::vector<std::vector<int>> matrix = {{1, 0, 3}};

    setZeroes(matrix);

    printMatrix(matrix);

    return 0;
}