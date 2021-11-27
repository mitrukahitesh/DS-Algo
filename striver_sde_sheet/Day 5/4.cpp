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

/*
    1. Find number of nodes, then remove the nth node
        O(n + n) time
        O(1) space
    2. Two Pointer
        O(n) time
        O(1) space
*/

// 1
ListNode *remove(ListNode *node, int n)
{
    if (node == NULL)
        return NULL;
    n--;
    if (n == 0)
    {
        ListNode *temp = node->next;
        delete node;
        return temp;
    }
    node->next = remove(node->next, n);
    return node;
}

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *temp = head;
    int nodes = 0;
    while (temp)
    {
        ++nodes;
        temp = temp->next;
    }
    if (n > nodes)
        return head;
    n = nodes - n + 1;
    return remove(head, n);
}

// 2
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *temp = new ListNode(0, head);
    ListNode *f = temp;
    ListNode *s = temp;
    for (int i = 0; i < n && f != NULL; ++i)
    {
        f = f->next;
    }
    if (!f)
        return head;
    while (f->next != NULL)
    {
        s = s->next;
        f = f->next;
    }
    s->next = s->next->next;
    return temp->next;
}