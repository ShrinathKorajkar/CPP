#include <iostream>
#include <vector>
#include <queue>

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

int widthOfBinaryTree(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    std::queue<std::pair<TreeNode *, unsigned long long>> queue;
    int ans = 0;

    queue.push({root, 1});

    while (!queue.empty())
    {
        unsigned long long firstIdx = queue.front().second;
        unsigned long long lastIdx = queue.back().second;

        ans = std::max(ans, (int)(lastIdx - firstIdx + 1));
        int size = queue.size();

        for (int i = 0; i < size; i++)
        {
            TreeNode *curr = queue.front().first;
            unsigned long long currIdx = queue.front().second;

            if (curr->left != nullptr)
            {
                queue.push({curr->left, 2 * currIdx});
            }
            if (curr->right != nullptr)
            {
                queue.push({curr->right, 2 * currIdx + 1});
            }

            queue.pop();
        }
    }

    return ans;
}

int main()
{
    int idx = 0;
    std::vector<int> preorder = {1, 2, 7, -1, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    TreeNode *root = buildTree(preorder, idx);

    return 0;
}