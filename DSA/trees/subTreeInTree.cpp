#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isIdentical(TreeNode *root1, TreeNode *root2)
{
    if (root1 == nullptr || root2 == nullptr)
    {
        return root1 == root2;
    }

    return root1->val == root2->val &&
           isIdentical(root1->left, root2->left) &&
           isIdentical(root1->right, root2->right);
}

bool isSubtree(TreeNode *root, TreeNode *subRoot)
{
    if (root == nullptr || subRoot == nullptr)
    {
        return root == subRoot;
    }

    if (root->val == subRoot->val && isIdentical(root, subRoot))
    {
        return true;
    }

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

int main()
{

    return 0;
}