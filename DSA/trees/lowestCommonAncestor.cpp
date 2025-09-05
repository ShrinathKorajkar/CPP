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

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == nullptr || root->val == p->val || root->val == q->val)
    {
        return root;
    }

    TreeNode *leftLCA = lowestCommonAncestor(root->left, p, q);
    TreeNode *rightLCA = lowestCommonAncestor(root->right, p, q);

    if (leftLCA == nullptr)
    {
        return rightLCA;
    }

    if (rightLCA == nullptr)
    {
        return leftLCA;
    }

    return root;
}

int main()
{
    /*
                1
              /    \
            2       3
          /       /   \
        7       4       5

    */
    int idx = 0;
    std::vector<int> preorder = {1, 2, 7, -1, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    TreeNode *root = buildTree(preorder, idx);

    TreeNode *lca = lowestCommonAncestor(root, new TreeNode(4), new TreeNode(5));
    std::cout << lca->val << std::endl;

    return 0;
}
