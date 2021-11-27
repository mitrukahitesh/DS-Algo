#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *head = new ListNode();
    ListNode *temp = head;
    int carry = 0;
    while (l1 != NULL && l2 != NULL)
    {
        int sum = l1->val + l2->val + carry;
        int ans = sum % 10;
        carry = sum / 10;
        temp->next = new ListNode(ans);
        temp = temp->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1 != NULL)
    {
        int sum = l1->val + carry;
        int ans = sum % 10;
        carry = sum / 10;
        temp->next = new ListNode(ans);
        temp = temp->next;
        l1 = l1->next;
    }
    while (l2 != NULL)
    {
        int sum = l2->val + carry;
        int ans = sum % 10;
        carry = sum / 10;
        temp->next = new ListNode(ans);
        temp = temp->next;
        l2 = l2->next;
    }
    if (carry != 0)
    {
        temp->next = new ListNode(carry);
    }
    return head->next;
}