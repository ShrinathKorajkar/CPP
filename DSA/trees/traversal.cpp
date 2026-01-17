#include <iostream>
#include <vector>
#include <queue>

struct Tree
{
    int data;
    Tree *left, *right;

    Tree()
    {
        data = 0;
        left = right = nullptr;
    }
};

Tree *buildTree(std::vector<int> preOrderElems, int &idx)
{
    if (preOrderElems[idx] == -1)
    {
        return nullptr;
    }

    Tree *root = new Tree();
    root->data = preOrderElems[idx];
    root->left = buildTree(preOrderElems, ++idx);
    root->right = buildTree(preOrderElems, ++idx);

    return root;
}

void printTreePreeOrder(Tree *tree)
{
    if (tree == nullptr)
    {
        return;
    }

    std::cout << tree->data << std::endl;
    printTreePreeOrder(tree->left);
    printTreePreeOrder(tree->right);
}

std::vector<int> printLevelOrder(Tree *root)
{
    std::vector<int> levelOrder;

    if (root == nullptr)
    {
        return levelOrder;
    }

    std::queue<Tree *> queue;
    queue.push(root);

    // queue.push(nullptr); // for printing level order in seperate lines

    while (!queue.empty())
    {
        Tree *node = queue.front();
        queue.pop();

        // if (node == nullptr && !queue.empty())
        // {
        //     std::cout << std::endl;
        //     queue.push(nullptr);
        // }
        // else if (node == nullptr)
        // {
        //     break;
        // }

        levelOrder.push_back(node->data);

        if (node->left != nullptr)
        {
            queue.push(node->left);
        }
        if (node->right != nullptr)
        {
            queue.push(node->right);
        }
    }

    return levelOrder;
}

// One more level order traversal using preorder
std::vector<std::vector<int>> ret;

void buildVector(Tree *root, int depth)
{
    if (root == NULL)
        return;
    if (ret.size() == depth)
        ret.push_back(std::vector<int>());

    ret[depth].push_back(root->data);
    buildVector(root->left, depth + 1);
    buildVector(root->right, depth + 1);
}

std::vector<std::vector<int>> levelOrder(Tree *root)
{
    buildVector(root, 0);
    return ret;
}

int main()
{
    std::vector<int> treeElements = {1, 2, -1, -1, 3, 4, -1, -1, -1};
    int idx = 0;

    printTreePreeOrder(buildTree(treeElements, idx));

    return 0;
}