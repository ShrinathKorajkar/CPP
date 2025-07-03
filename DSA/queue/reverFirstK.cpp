#include <iostream>
#include <queue>
#include <stack>

std::queue<int> reverseFirstK(std::queue<int> q, int k)
{
    // code here
    int size = q.size();
    std::stack<int> stack;

    if (size < k)
    {
        return q;
    }

    int rem = size - k;

    while (k-- > 0)
    {
        stack.push(q.front());
        q.pop();
    }

    while (!stack.empty())
    {
        q.push(stack.top());
        stack.pop();
    }

    while (rem-- > 0)
    {
        q.push(q.front());
        q.pop();
    }

    return q;
}
