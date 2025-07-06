/*
    Stack with getMin() -> get min in O(1)
*/
#include <iostream>
#include <stack>

class MinStack
{
    std::stack<int> s1, s2;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        s1.push(val);
        if (s2.empty() || s2.top() >= val)
        {
            s2.push(val);
        }
    }

    void pop()
    {
        if (!s2.empty() && s2.top() == s1.top())
        {
            s2.pop();
        }
        s1.pop();
    }

    int top()
    {
        return s1.top();
    }

    int getMin()
    {
        return s2.top();
    }
};

int main()
{

    return 0;
}
