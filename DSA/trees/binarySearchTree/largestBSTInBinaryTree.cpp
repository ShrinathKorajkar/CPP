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

struct BSTInfo
{
    int max = INT_MIN;
    int min = INT_MAX;
    int size = 0;
};

BSTInfo helper(TreeNode *root)
{
    if (root == nullptr)
    {
        return BSTInfo();
    }

    BSTInfo leftInfo = helper(root->left);
    BSTInfo rightInfo = helper(root->right);
    BSTInfo ans;

    if (leftInfo.max < root->val && rightInfo.min > root->val)
    {
        ans.min = std::min(root->val, leftInfo.min);
        ans.max = std::max(root->val, rightInfo.max);
        ans.size = leftInfo.size + rightInfo.size + 1;
    }
    else
    {
        ans.min = INT_MIN;
        ans.max = INT_MAX;
        ans.size = std::max(leftInfo.size, rightInfo.size);
    }

    return ans;
}

int largestBSTinBT(TreeNode *root)
{
    BSTInfo info = helper(root);
    return info.size;
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);
    root->right = new TreeNode(15);
    root->right->right = new TreeNode(7);

    std::cout << largestBSTinBT(root) << std::endl;

    return 0;
}