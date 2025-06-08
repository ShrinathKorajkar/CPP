#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    ListNode *newHead = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;

    return newHead;
}

ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *currNode = head;
    // int i = k - 1;
    int i = k;
    while (i-- > 0)
    {
        if (currNode == nullptr)
        {
            return head;
        }
        currNode = currNode->next;
    }

    ListNode *nextNode = reverseKGroup(currNode, k);

    ListNode *currNextNode;
    currNode = head;
    i = k;
    while (i-- > 0)
    {
        currNextNode = currNode->next;
        currNode->next = nextNode;
        nextNode = currNode;
        currNode = currNextNode;
    }

    // ListNode *nextNode = nullptr;
    // if (currNode != nullptr)
    // {
    //     nextNode = reverseKGroup(currNode->next, k);
    //    currNode->next = nullptr;
    // }

    // ListNode *newHead = reverseList(head);
    // head->next = nextNode;

    return nextNode;
}

int main()
{

    return 0;
}