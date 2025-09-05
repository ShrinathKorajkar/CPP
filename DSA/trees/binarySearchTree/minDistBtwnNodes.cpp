#include <iostream>
#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int helper(TreeNode *root, int &left)
{
    if (root == nullptr)
    {
        return INT_MAX;
    }

    int leftMin = helper(root->left, left);
    int min = std::abs(left - root->val);
    left = root->val;
    int rightMin = helper(root->right, left);

    return std::min(min, std::min(leftMin, rightMin));
}

int minDiffInBST(TreeNode *root)
{
    int left = INT_MAX;
    return helper(root, left);
}

int main()
{

    return 0;
}