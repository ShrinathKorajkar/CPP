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

int index = 0;

TreeNode *buildBST(const std::vector<int> &preorder, int upper)
{
    if (index == preorder.size())
        return nullptr;

    int val = preorder[index];
    if (val > upper)
        return nullptr;

    TreeNode *root = new TreeNode(val);
    index++;

    root->left = buildBST(preorder, val - 1);
    root->right = buildBST(preorder, upper);

    return root;
}

TreeNode *bstFromPreorder(std::vector<int> &preorder)
{
    return buildBST(preorder, INT_MAX);
}

// The below approach will take O(N^2) if tree is skewed and sorted descending order
// The while loop will search till end every time.
TreeNode *bstHelper(std::vector<int> &preorder, int start, int end)
{
    if (start > end)
    {
        return nullptr;
    }

    TreeNode *root = new TreeNode(preorder[start]);
    int rightStart = start + 1;

    while (rightStart <= end && preorder[start] < preorder[rightStart])
    {
        rightStart++;
    }

    root->left = bstHelper(preorder, start + 1, rightStart - 1);
    root->right = bstHelper(preorder, rightStart, end);

    return root;
}

int main()
{

    return 0;
}