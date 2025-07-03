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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *ans = new ListNode();
    ListNode *curr = ans;
    int sum = 0;

    while (l1 != nullptr || l2 != nullptr || sum != 0)
    {
        sum += (l1 == nullptr) ? 0 : l1->val;
        sum += (l2 == nullptr) ? 0 : l2->val;
        curr->next = new ListNode(sum % 10);
        curr = curr->next;
        sum /= 10;

        if (l1 != nullptr)
        {
            l1 = l1->next;
        }
        if (l2 != nullptr)
        {
            l2 = l2->next;
        }
    }

    return ans->next;
}

int main()
{
    ListNode node2(3);
    ListNode node3(4, &node2);
    ListNode node(2, &node3);

    ListNode node1(4);
    ListNode node4(6, &node1);
    ListNode node5(5, &node4);

    ListNode *ans = addTwoNumbers(&node, &node5);
    return 0;
}