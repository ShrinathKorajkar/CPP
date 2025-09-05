#include <iostream>
#include <vector>

/*
    You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake.
    Recover the tree without changing its structure.
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

TreeNode *prev = nullptr;
TreeNode *first = nullptr;
TreeNode *second = nullptr;

void inorder(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    inorder(root->left);

    if (prev != nullptr && prev->val > root->val)
    {
        if (first == nullptr)
        {
            first = prev;
        }
        second = root;
    }
    prev = root;
    inorder(root->right);
}

void recoverTree(TreeNode *root)
{
    inorder(root);
    if (first != nullptr)
    {
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
}

int main()
{

    return 0;
}