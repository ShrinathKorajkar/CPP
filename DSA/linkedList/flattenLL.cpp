#include <iostream>

class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;

    Node(int val) : val(val), next(nullptr), child(nullptr) {}
};

// Utility function to print list
void printList(Node *head)
{
    while (head)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

Node *flattenSingleLL(Node *head)
{
    Node *curr = head;
    while (curr != nullptr)
    {
        if (curr->child != nullptr)
        {
            Node *prev = curr->child;
            while (prev->next != nullptr) // this can be removed by maintining childnode pointer
            {
                prev = prev->next;
            }
            prev->next = curr->next;
            curr->next = curr->child;
            curr->child = nullptr;
        }
        curr = curr->next;
    }
    return head;
}

Node *flatten(Node *head)
{
    Node *curr = head;
    while (curr != nullptr)
    {
        if (curr->child != nullptr)
        {
            Node *next = curr->next;
            curr->next = flatten(curr->child);
            curr->next->prev = curr;
            curr->child = nullptr;

            while (curr->next != nullptr)
            {
                curr = curr->next;
            }

            if (next != nullptr)
            {
                curr->next = next;
                next->prev = curr;
            }
        }
        curr = curr->next;
    }
    return head;
}

int main()
{

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    head->next->child = new Node(7);
    head->next->child->next = new Node(8);
    head->next->child->next->next = new Node(9);
    head->next->child->next->child = new Node(10);

    std::cout << "Original (hierarchical):" << std::endl;
    std::cout << "1 -> 2 -> 3 -> 4" << std::endl;
    std::cout << "     |" << std::endl;
    std::cout << "     7 -> 8 -> 9" << std::endl;
    std::cout << "          |" << std::endl;
    std::cout << "          10" << std::endl;

    head = flattenSingleLL(head);

    std::cout << "\nFlattened list: ";
    printList(head);

    return 0;
}