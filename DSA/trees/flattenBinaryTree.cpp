#include <iostream>
#include <vector>
/*
    Right child pointer points to the next node in the list and the left child pointer is always null.
    The "linked list" should be in the same order as a pre-order traversal of the binary tree.
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

void flattenHelper(TreeNode *root, TreeNode **head)
{
    if (root == nullptr)
    {
        return;
    }

    flattenHelper(root->right, head);
    flattenHelper(root->left, head);

    root->left = nullptr;
    root->right = *head;
    *head = root;
}

void flatten(TreeNode *root)
{
    TreeNode *head = nullptr;
    flattenHelper(root, &head);
}

int main()
{

    return 0;
}