#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseList(ListNode *head, int right, ListNode *&lastNode)
{
    if (head == nullptr || head->next == nullptr || right == 1)
    {
        lastNode = head->next;
        return head;
    }

    ListNode *newHead = reverseList(head->next, right - 1, lastNode);
    head->next->next = head;
    head->next = lastNode;

    return newHead;
}

ListNode *reverseBetween(ListNode *head, int left, int right)
{
    if (left == 1)
    {
        ListNode *lastNode = nullptr;
        return reverseList(head, right, lastNode);
    }

    head->next = reverseBetween(head->next, left - 1, right - 1);
    return head;
}

int main()
{

    return 0;
}