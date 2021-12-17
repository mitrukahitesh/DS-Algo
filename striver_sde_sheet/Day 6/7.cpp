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

// O(n) + O(n - (k % n)) time
// O(1) space
ListNode *rotateRight(ListNode *head, int k)
{
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    // Compute n
    ListNode *temp = head;
    int len = 1;
    while (temp->next != NULL)
    {
        len++;
        temp = temp->next;
    }

    // Point last node to head
    temp->next = head;

    // Find actual number of rotation required
    k = k % len;

    // Go to the node that is to be last now
    k = len - k;
    temp = head;
    for (int i = 1; i < k; ++i)
    {
        temp = temp->next;
    }

    // Make the node head and break connection
    head = temp->next;
    temp->next = NULL;

    return head;
}