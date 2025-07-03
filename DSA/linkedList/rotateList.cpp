#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode *head)
{
    ListNode *start = head;
    while (start != nullptr)
    {
        std::cout << start->val << "->";
        start = start->next;
    }
    std::cout << std::endl;
}

ListNode *rotateRight(ListNode *head, int k)
{
    if (head == nullptr || head->next == nullptr || k == 0)
    {
        return head;
    }

    ListNode *tail = head;
    int length = 1;
    while (tail->next != nullptr)
    {
        tail = tail->next;
        length++;
    }

    tail->next = head;
    k = k % length;

    tail = head;
    for (int i = 1; i < length - k; i++)
    {
        tail = tail->next;
    }

    ListNode *newHead = tail->next;
    tail->next = nullptr;

    return newHead;
}

int main()
{

    return 0;
}