#include <iostream>
#include <vector>
#include <algorithm>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *buildBST(std::vector<int> &arr, int start, int end)
{
    if (start > end)
    {
        return nullptr;
    }

    int mid = start + (end - start) / 2;

    TreeNode *root = new TreeNode(arr[mid]);
    root->left = buildBST(arr, start, mid - 1);
    root->right = buildBST(arr, mid + 1, end);

    return root;
}

TreeNode *arrToBST(std::vector<int> &arr)
{
    return buildBST(arr, 0, arr.size() - 1);
}

void getInorder(TreeNode *root, std::vector<int> &inorder)
{
    if (root == nullptr)
    {
        return;
    }
    getInorder(root->left, inorder);
    inorder.push_back(root->val);
    getInorder(root->right, inorder);
}

TreeNode *canMerge(std::vector<TreeNode *> &trees)
{
    std::vector<int> inorder;
    int n = trees.size();
    for (int i = 0; i < n; i++)
    {
        getInorder(trees[i], inorder);
    }

    std::sort(inorder.begin(), inorder.end());

    return arrToBST(inorder);
}

int main()
{

    return 0;
}