#include <iostream>
#include <unordered_map>
/*
    Copy List with Random Pointer
*/
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *copyRandomList1(Node *head)
{
    Node *newHead = nullptr;
    if (head == nullptr)
    {
        return newHead;
    }
    newHead = new Node(head->val);

    std::unordered_map<Node *, Node *> map;
    Node *oldTemp = head;
    Node *newTemp = newHead;

    while (oldTemp != nullptr && oldTemp->next != nullptr)
    {
        map[oldTemp] = newTemp;
        Node *copy = new Node(oldTemp->next->val);
        newTemp->next = copy;
        oldTemp = oldTemp->next;
        newTemp = newTemp->next;
    }
    map[oldTemp] = newTemp;

    oldTemp = head;
    while (oldTemp != nullptr)
    {
        if (oldTemp->random)
            map[oldTemp]->random = map[oldTemp->random];
        else
            map[oldTemp]->random = nullptr;
        oldTemp = oldTemp->next;
    }

    return newHead;
}

Node *copyRandomList2(Node *head)
{
    // STEP 1: PASS 1
    // Creating a copy A->A'->B->B'->C->C'->D->D'
    Node *node = head;
    while (node)
    {
        Node *temp = node->next;
        node->next = new Node(node->val);
        node->next->next = temp;
        node = temp;
    }

    // STEP 2: PASS 2
    // Now copy the random pointer (if exists) of the old nodes to their copy new nodes.
    node = head;
    while (node)
    {
        if (node->random)
            node->next->random = node->random->next;
        node = node->next->next;
    }

    // STEP 3: PASS 3
    // unmerge the nodes
    Node *ans = new Node(0); // first node is a dummy node
    Node *helper = ans;

    while (head)
    {
        helper->next = head->next;
        helper = helper->next;

        // Restoring the old linklist, by removing the alternative newly added nodes
        head->next = head->next->next;
        head = head->next;
    }
    return ans->next;
}

int main()
{

    return 0;
}
