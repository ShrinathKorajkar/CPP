#include <iostream>

/*
    Floyd's cycle detection algo
*/

struct ListNode
{
    int val;
    ListNode *next;
};

ListNode *removeCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            break;
        }
    }
    if (fast == nullptr || fast->next == nullptr)
    {
        return nullptr;
    }
    ListNode *prev = fast;
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        prev = fast;
        fast = fast->next;
    }
    prev->next = nullptr;
    return slow;
}

int main()
{

    return 0;
}