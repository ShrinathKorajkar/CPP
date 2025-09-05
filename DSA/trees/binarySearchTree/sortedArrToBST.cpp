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

int main()
{
    std::vector<int> arr = {-10, -3, 0, 5, 9};
    return 0;
}
