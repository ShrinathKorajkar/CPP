#include <iostream>
#include <stack>
#include <vector>

std::vector<int> calcStockSpan(std::vector<int> price)
{
    std::stack<int> st;
    int len = price.size();
    std::vector<int> ans(len);

    for (int i = 0; i < len; i++)
    {
        while (!st.empty() && price[st.top()] <= price[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            ans[i] = i + 1;
            st.push(i);
            continue;
        }

        ans[i] = i - st.top();
        st.push(i);
    }

    return ans;
}

int main()
{
    std::vector<int> price = {100, 80, 60, 70, 60, 75, 85};

    std::vector<int> stockSpan = calcStockSpan(price);
    for (auto span : stockSpan)
    {
        std::cout << span << " ";
    }
    std::cout << std::endl;

    return 0;
}