#include <iostream>
#include <vector>

// void solveMaze(std::vector<std::vector<int>> &maze, const int &mazeRowLen, const int &mazeColLen, std::vector<std::string> &paths, std::string currentPath, int row, int col, std::vector<std::vector<bool>> &visited)
void solveMaze(std::vector<std::vector<int>> &maze, const int &mazeRowLen, const int &mazeColLen, std::vector<std::string> &paths, std::string currentPath, int row, int col)
{
    // if (row == mazeRowLen || row < 0 || col < 0 || col == mazeColLen || maze[row][col] == 0 || visited[row][col])
    if (row == mazeRowLen || row < 0 || col < 0 || col == mazeColLen || maze[row][col] == 0)
    {
        return;
    }

    if (row == mazeRowLen - 1 && col == mazeColLen - 1)
    {
        paths.emplace_back(currentPath);
        return;
    }

    // visited[row][col] = true;

    // solveMaze(maze, mazeRowLen, mazeColLen, paths, currentPath + "U", row - 1, col, visited);
    // solveMaze(maze, mazeRowLen, mazeColLen, paths, currentPath + "L", row, col - 1, visited);
    // solveMaze(maze, mazeRowLen, mazeColLen, paths, currentPath + "R", row, col + 1, visited);
    // solveMaze(maze, mazeRowLen, mazeColLen, paths, currentPath + "D", row + 1, col, visited);

    // visited[row][col] = false;

    maze[row][col] = 0;

    solveMaze(maze, mazeRowLen, mazeColLen, paths, currentPath + "U", row - 1, col);
    solveMaze(maze, mazeRowLen, mazeColLen, paths, currentPath + "L", row, col - 1);
    solveMaze(maze, mazeRowLen, mazeColLen, paths, currentPath + "R", row, col + 1);
    solveMaze(maze, mazeRowLen, mazeColLen, paths, currentPath + "D", row + 1, col);

    maze[row][col] = 1;
}

std::vector<std::string> ratInMaze(std::vector<std::vector<int>> &maze)
{
    int mazeRowLen = maze.size();
    int mazeColLen = maze[0].size();
    std::vector<std::string> paths;
    // std::vector<std::vector<bool>> visited(mazeRowLen, std::vector<bool>(mazeColLen, false));
    // solveMaze(maze, mazeRowLen, mazeColLen, paths, "", 0, 0, visited);
    solveMaze(maze, mazeRowLen, mazeColLen, paths, "", 0, 0);
    return paths;
}

int main()
{
    std::vector<std::vector<int>> maze = {{1, 0, 0, 0},
                                          {1, 1, 0, 1},
                                          {1, 1, 0, 0},
                                          {0, 1, 1, 1}};

    std::vector<std::string> ans = ratInMaze(maze);
    for (std::string path : ans)
    {
        std::cout << path << std::endl;
    }
    return 0;
}