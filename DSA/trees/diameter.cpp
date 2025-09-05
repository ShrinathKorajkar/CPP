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

int calcHeight(TreeNode *root, int &ans)
{
    if (root == nullptr)
    {
        return 0;
    }

    int leftHeight = calcHeight(root->left, ans);
    int rightHeight = calcHeight(root->right, ans);
    int diameter = leftHeight + rightHeight;
    ans = std::max(ans, diameter);

    return std::max(leftHeight, rightHeight) + 1;
}

int diameterOfBinaryTree(TreeNode *root)
{
    int ans = 0;
    calcHeight(root, ans);
    return ans;
}

int main()
{
    int idx = 0;
    std::vector<int> preorder = {1, 2, 7, -1, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    TreeNode *root = buildTree(preorder, idx);

    std::cout << diameterOfBinaryTree(root) << std::endl;

    return 0;
}