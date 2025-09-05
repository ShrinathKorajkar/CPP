#include <iostream>
#include <stack>

/**
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator* obj = new BSTIterator(root);
    int param_1 = obj->next();
    bool param_2 = obj->hasNext();

    Could you implement next() and hasNext() to run in average O(1) time and use O(h) memory, where h is the height of the tree?
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

class BSTIterator
{
    std::stack<TreeNode *> stack;

public:
    BSTIterator(TreeNode *root)
    {
        while (root != nullptr)
        {
            stack.push(root);
            root = root->left;
        }
    }

    int next()
    {
        TreeNode *leftMost = stack.top();
        stack.pop();

        TreeNode *root = leftMost->right;
        while (root != nullptr)
        {
            stack.push(root);
            root = root->left;
        }

        return leftMost->val;
    }

    bool hasNext()
    {
        return !stack.empty();
    }
};

int main()
{

    return 0;
}