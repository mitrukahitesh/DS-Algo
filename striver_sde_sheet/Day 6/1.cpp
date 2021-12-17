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
    Brute force:
    For every node in L2, traverse every node in L1
    O(nm) time
    O(1) space

    Better:
    Using hashset - Hash every node of L1, then traverse L2
    O(n + m) time
    O(n) space

    Optimized (Best):
    Find difference in length (d), move the longer list's dummy node d steps
    Move both lists simultaneously, then return when both nodes equal
    O(max(n, m) + abs(n - m) + min(n, m)) time = O(2m)
    O(1) space

    Optimized (Second Best but Recommended):
    O(2m)
    O(1)
*/

// Better
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    set<ListNode *> nodes;
    ListNode *a = headA;
    ListNode *b = headB;
    while (a != NULL)
    {
        nodes.insert(a);
        a = a->next;
    }
    while (b != NULL)
    {
        if (nodes.find(b) != nodes.end())
            return b;
        b = b->next;
    }
    return NULL;
}

// Optimized (Best)
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *a = headA;
    ListNode *b = headB;
    int n = 0, m = 0;
    while (a != NULL || b != NULL)
    {
        if (a != NULL)
        {
            ++n;
            a = a->next;
        }
        if (b != NULL)
        {
            ++m;
            b = b->next;
        }
    }
    int diff = abs(n - m);
    a = n > m ? headA : headB;
    b = n > m ? headB : headA;
    while (diff--)
        a = a->next;
    while (a != b)
    {
        a = a->next;
        b = b->next;
    }
    return a;
}

// Optimized (Second Best but Recommended)
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *a = headA;
    ListNode *b = headB;
    int n = 0, m = 1;
    while (a != b)
    {
        a = a == NULL ? headB : a->next;
        b = b == NULL ? headA : b->next;
    }
    return a;
}