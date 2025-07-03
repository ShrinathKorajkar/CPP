#include <iostream>
#include <stack>
#include <vector>

/*
    Celeb => known by everyone, knows no one
    if a[i][j] == 1, => i knows j
*/

int getCelebrity(std::vector<std::vector<int>> arr)
{
    int celeb = -1;
    std::stack<int> stack;
    for (int i = 0; i < arr.size(); i++)
    {
        stack.push(i);
    }

    while (stack.size() > 1)
    {
        int i = stack.top();
        stack.pop();
        int j = stack.top();
        stack.pop();
        if (arr[i][j] == 1)
        {
            stack.push(j);
        }
        else
        {
            stack.push(i);
        }
    }

    celeb = stack.top();
    for (int i = 0; i < arr.size(); i++)
    {
        if (i != celeb && (arr[i][celeb] == 0 || arr[celeb][i] == 1))
        {
            celeb = -1;
            break;
        }
    }

    return celeb;
}

int main()
{
    std::vector<std::vector<int>> arr = {{0, 1, 0},
                                         {0, 0, 0},
                                         {0, 1, 0}};

    std::cout << getCelebrity(arr) << std::endl;
    return 0;
}