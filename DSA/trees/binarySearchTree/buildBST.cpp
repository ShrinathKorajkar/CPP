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

TreeNode *insertIntoBST(TreeNode *&root, int elem)
{
    if (root == nullptr)
    {
        return new TreeNode(elem);
    }

    if (root->val < elem)
    {
        root->right = insertIntoBST(root->right, elem);
    }
    else
    {

        root->left = insertIntoBST(root->left, elem);
    }

    return root;
}

void printInOrder(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    printInOrder(root->left);
    std::cout << root->val << " ";
    printInOrder(root->right);
}

TreeNode *buildBST(std::vector<int> arr)
{
    TreeNode *root = nullptr;
    for (auto elem : arr)
    {
        root = insertIntoBST(root, elem);
    }

    return root;
}

TreeNode *findInOrderSuccessor(TreeNode *root)
{
    while (root != nullptr && root->left != nullptr)
    {
        root = root->left;
    }

    return root;
}

TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (key < root->val)
    {
        root->left = deleteNode(root->left, key);
        return root;
    }

    if (key > root->val)
    {
        root->right = deleteNode(root->right, key);
        return root;
    }

    TreeNode *ans;
    if (root->left == nullptr)
    {
        ans = root->right;
        delete root;
        return ans;
    }

    if (root->right == nullptr)
    {
        ans = root->left;
        delete root;
        return ans;
    }

    TreeNode *inOrderSuccessor = findInOrderSuccessor(root->right);
    root->val = inOrderSuccessor->val;
    root->right = deleteNode(root->right, root->val);

    return root;
}

int main()
{
    std::vector<int> arr = {3, 2, 1, 5, 6, 4};

    TreeNode *root = buildBST(arr);
    printInOrder(root);
    std::cout << std::endl;

    return 0;
}