#include <iostream>
#include <vector>
#include <queue>
#include <map>

/*
    horizontal dist
*/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *buildTree(std::vector<int> preOrderElems, int &idx)
{
    if (preOrderElems[idx] == -1)
    {
        return nullptr;
    }

    TreeNode *root = new TreeNode();
    root->val = preOrderElems[idx];
    root->left = buildTree(preOrderElems, ++idx);
    root->right = buildTree(preOrderElems, ++idx);

    return root;
}

std::vector<int> topViewOfTree(TreeNode *root)
{
    std::vector<int> ans;
    std::queue<std::pair<TreeNode *, int>> queue;
    std::map<int, int> map;

    if (root == nullptr)
    {
        return ans;
    }

    queue.push({root, 0});
    // queue.push({nullptr, 0});

    // int currLevel = 0;

    while (!queue.empty())
    {
        TreeNode *node = queue.front().first;
        int currDist = queue.front().second;
        queue.pop();

        // if (node == nullptr)
        // {
        //     if (queue.empty())
        //     {
        //         break;
        //     }
        //     queue.push({nullptr, 0});
        //     currLevel++;
        //     continue;
        // }

        // if (currLevel == std::abs(currDist))
        // {
        //     ans.push_back(node->val);
        // }

        if (map.find(currDist) == map.end()) // remove this condition for bottom view
        {
            map[currDist] = node->val;
        }

        if (node->left != nullptr)
        {
            queue.push({node->left, currDist - 1});
        }

        if (node->right != nullptr)
        {
            queue.push({node->right, currDist + 1});
        }
    }

    for (auto it : map)
    {
        ans.push_back(it.second);
    }

    return ans;
}

int main()
{
    int idx = 0;
    std::vector<int> preorder = {1, 2, 7, -1, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    TreeNode *root = buildTree(preorder, idx);

    std::vector<int> ans = topViewOfTree(root);
    for (auto elem : ans)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}