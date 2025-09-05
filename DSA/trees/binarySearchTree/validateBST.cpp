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

bool helper2(TreeNode *root, TreeNode *minNode, TreeNode *maxNode)
{
    if (root == nullptr)
    {
        return true;
    }

    if (minNode != nullptr && minNode->val >= root->val)
    {
        return false;
    }

    if (maxNode != nullptr && maxNode->val <= root->val)
    {
        return false;
    }

    return helper2(root->left, minNode, root) && helper2(root->right, root, maxNode);
}

// Not working in leatcode
bool helper(TreeNode *root, std::vector<int> &inorder, int &idx)
{
    if (root == nullptr)
    {
        return true;
    }

    bool left = helper(root->left, inorder, idx);
    if (left == false || inorder[idx - 1] >= root->val && root->val != INT_MIN)
    {
        return false;
    }

    inorder.push_back(root->val);
    idx++;

    return helper(root->right, inorder, idx);
}

bool isValidBST(TreeNode *root)
{
    std::vector<int> inorder;
    inorder.push_back(INT_MIN);
    int index = 1;
    return helper(root, inorder, index);
}
