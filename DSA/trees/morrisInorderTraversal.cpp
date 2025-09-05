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

// O(2n) => O(n)
std::vector<int> inorderTraversal(TreeNode *root)
{
    std::vector<int> ans;
    TreeNode *curr = root;

    while (curr != nullptr)
    {
        if (curr->left == nullptr)
        {
            ans.push_back(curr->val);
            curr = curr->right;
            continue;
        }

        TreeNode *inorderPredecessor = curr->left;
        while (inorderPredecessor->right != nullptr && inorderPredecessor->right != curr)
        {
            inorderPredecessor = inorderPredecessor->right;
        }

        if (inorderPredecessor->right == nullptr)
        {
            inorderPredecessor->right = curr;
            curr = curr->left;
        }
        else
        {
            inorderPredecessor->right = nullptr;
            ans.push_back(curr->val);
            curr = curr->right;
        }
    }

    return ans;
}

int main()
{
    int idx = 0;
    std::vector<int> preorder = {1, 2, 7, -1, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    TreeNode *root = buildTree(preorder, idx);

    std::vector<int> morrisInorder = inorderTraversal(root);
    for (auto elem : morrisInorder)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}