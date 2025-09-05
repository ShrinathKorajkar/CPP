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

void printTreePreeOrder(TreeNode *tree)
{
    if (tree == nullptr)
    {
        return;
    }

    std::cout << tree->val << " ";
    printTreePreeOrder(tree->left);
    printTreePreeOrder(tree->right);
}

TreeNode *buildTreeHelper(std::vector<int> &preorder, std::vector<int> &inorder, int &curr, int left, int right)
{
    if (left > right)
    {
        return nullptr;
    }

    TreeNode *root = new TreeNode(preorder[curr]);
    curr++; // will be curr--; if postorder

    int rootIdx = 0;
    for (int i = left; i <= right; i++)
    {
        if (root->val == inorder[i])
        {
            rootIdx = i;
            break;
        }
    }

    // These lines will change order if postorder
    root->left = buildTreeHelper(preorder, inorder, curr, left, rootIdx - 1);
    root->right = buildTreeHelper(preorder, inorder, curr, rootIdx + 1, right);

    return root;
}

TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder)
{
    int curr = 0, left = 0, right = inorder.size() - 1; // curr = postorder.size() - 1; if postorder given
    return buildTreeHelper(preorder, inorder, curr, left, right);
}

int main()
{
    std::vector<int> preorder = {3, 9, 20, 15, 7};
    std::vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode *root = buildTree(preorder, inorder);
    printTreePreeOrder(root);

    return 0;
}