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

bool isPalindrome(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    fast = head;
    slow = reverseList(slow);

    while (slow != nullptr)
    {
        if (slow->val != fast->val)
        {
            return false;
        }
        slow = slow->next;
        fast = fast->next;
    }
    return true;
}

int main()
{
    ListNode node1(1);
    ListNode node2(2, &node1);
    ListNode node3(1, &node2);
    ListNode node(1, &node3);

    // printList(&node);

    std::cout << isPalindrome(&node) << std::endl;
    return 0;
}