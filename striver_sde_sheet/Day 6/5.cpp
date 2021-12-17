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
    Naive:
        Using hashset
    O(n) time
    O(n) space
    
    Optimal:
        Tortoise and Hare
        Find collision point of s & f
        Then find the node where cycle begins
    O(n) time
    O(1) space
    Good explanation in video
    2(l1 + l2) = l1 + l2 + nC
    l1 + l2 = nC
    l1 = nC - l2
*/

// Optimal
ListNode *detectCycle(ListNode *head)
{
    ListNode *s = head;
    ListNode *f = head;
    do
    {
        if (f == NULL || f->next == NULL || f->next->next == NULL)
            return NULL;
        s = s->next;
        f = f->next->next;
    } while (s != f);
    s = head;
    while (s != f)
    {
        s = s->next;
        f = f->next;
    }
    return s;
}