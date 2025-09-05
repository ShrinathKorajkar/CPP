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

void findKthLevel(TreeNode *root, std::vector<int> &kthLevel, int k)
{
    if (root == nullptr)
    {
        return;
    }

    if (1 == k)
    {
        kthLevel.push_back(root->val);
        return;
    }

    findKthLevel(root->left, kthLevel, k - 1);
    findKthLevel(root->right, kthLevel, k - 1);
}

std::vector<int> kthLevelOfBinaryTree(TreeNode *root, int k)
{
    std::vector<int> kthLevel;
    findKthLevel(root, kthLevel, k);
    return kthLevel;
}

int main()
{
    int idx = 0;
    std::vector<int> preorder = {1, 2, 7, -1, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    TreeNode *root = buildTree(preorder, idx);

    std::vector<int> ans = kthLevelOfBinaryTree(root, 3);
    for (auto elem : ans)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    return 0;
}