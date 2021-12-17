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

// pre holds the last node of previous group
// next holds the node that is to be brought to front of the current group
// cur holds last node that is in correct position
// cur->next holds the node that is to be taken as nex in next turn

// The idea is to transform
// pre pre->next ... nex to
// pre nex pre->next
// i.e bring nex (first node not in correct place) to front of current group

// O(2n)
ListNode *reverseKGroup(ListNode *head, int k)
{
    if (head == NULL || k == 1)
        return head;
    ListNode *dummy = new ListNode(0, head);
    ListNode *pre = dummy, *cur = dummy, *nex = dummy;
    int n = 0;
    while (cur->next != NULL)
    {
        ++n;
        cur = cur->next;
    }
    while (n >= k)
    {
        cur = pre->next;
        nex = cur->next;
        for (int i = 0; i < k - 1; ++i)
        {
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        pre = cur;
        n -= k;
    }
    return dummy->next;
}