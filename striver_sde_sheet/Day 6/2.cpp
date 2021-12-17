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
    Brute force: Use hashing
    O(n) time
    O(n) space

    Optimal: Tortoise and Hare
    O(n) time
    O(1) space 
*/

// Optimal
bool hasCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next)
    {

        fast = fast->next->next;
        slow = slow->next;

        if (slow == fast)
            return true;
    }

    return false;
}