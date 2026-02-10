#include <iostream>
#include <vector>

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

class BST
{
    Node *root;

    Node *searchHelper(const int &val)
    {
        Node *currNode = root;
        Node *resultNode = nullptr;

        while (currNode != nullptr)
        {
            if (currNode->data == val)
            {
                resultNode = currNode;
                break;
            }

            if (currNode->data < val)
            {
                currNode = currNode->right;
            }
            else
            {
                currNode = currNode->left;
            }
        }

        return resultNode;
    }

    Node *searchHelper(Node *currNode, const int &val)
    {
        if (currNode == nullptr || currNode->data == val)
        {
            return currNode;
        }

        if (currNode->data < val)
        {
            return searchHelper(currNode->right, val);
        }
        else
        {
            return searchHelper(currNode->left, val);
        }
    }

public:
    BST(Node *root = nullptr) : root(root) {}

    Node *searchNode(const int &val)
    {
        // return searchHelper(root, val);
        return searchHelper(val);
    }
};

void findInOrderTraversal(Node *root, std::vector<int> &inorder)
{
    if (root == nullptr)
    {
        return;
    }

    findInOrderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    findInOrderTraversal(root->right, inorder);
}

bool isBSTValid(Node *root)
{
    std::vector<int> inorder;
    findInOrderTraversal(root, inorder);

    for (int i = 0; i < inorder.size() - 1; i++)
    {
        if (inorder[i] > inorder[i + 1])
        {
            return false;
        }
    }

    return true;
}

/*
     5
  2     7
0   3
*/
void testSearchInBST()
{
    Node *root = new Node(5);
    root->left = new Node(2);
    root->left->left = new Node(0);
    root->left->right = new Node(3);
    root->right = new Node(7);

    std::vector<int> testValues = {2, 1, 7, 5, 0, 8};

    BST *bst = new BST(root);

    if (isBSTValid(root))
    {
        std::cout << "check: BST is valid" << std::endl;
    }
    else
    {
        std::cout << "check: BST is not valid: Test failed!!!" << std::endl;
        return;
    }

    for (auto testValue : testValues)
    {
        Node *resultNode = bst->searchNode(testValue);
        if (resultNode != nullptr)
        {
            std::cout << "found the node for : " << testValue << " : " << resultNode->data << std::endl;
        }
        else
        {
            std::cout << "Did not find any node for : " << testValue << std::endl;
        }
    }
}

int main()
{
    testSearchInBST();
    return 0;
}
