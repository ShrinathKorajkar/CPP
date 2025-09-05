#include <iostream>
#include <vector>

/*
    find inorder predecessor and successor of BST key
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

void helper(std::vector<int> &ans, TreeNode *root, int key, TreeNode *pred, TreeNode *succ)
{
    if (root == nullptr)
    {
        return;
    }

    if (root->val < key)
    {
        helper(ans, root->right, key, root, succ);
        return;
    }

    if (root->val > key)
    {
        helper(ans, root->left, key, pred, root);
        return;
    }

    TreeNode *leftMostInRight = root->right;
    TreeNode *rightMostInLeft = root->left;

    while (rightMostInLeft != nullptr && rightMostInLeft->right != nullptr)
    {
        rightMostInLeft = rightMostInLeft->right;
    }

    while (leftMostInRight != nullptr && leftMostInRight->left != nullptr)
    {
        leftMostInRight = leftMostInRight->left;
    }

    if (rightMostInLeft != nullptr)
    {
        ans[0] = rightMostInLeft->val;
    }
    else
    {
        ans[0] = pred->val;
    }

    if (leftMostInRight != nullptr)
    {
        ans[1] = leftMostInRight->val;
    }
    else
    {
        ans[1] = succ->val;
    }
}

std::vector<int> findInorderPredSucc(TreeNode *root, int key)
{
    std::vector<int> ans(2, 0);
    helper(ans, root, key, nullptr, nullptr);
    return ans;
}

int main()
{

    return 0;
}