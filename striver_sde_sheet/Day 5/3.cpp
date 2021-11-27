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

// O(n1 + n2) time
// O(1) space
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (l1 == NULL)
        return l2;
    else if (l2 == NULL)
        return l1;
    ListNode *root = NULL;
    if (l1->val <= l2->val)
    {
        root = l1;
        l1 = l1->next;
    }
    else
    {
        root = l2;
        l2 = l2->next;
    }
    root->next = NULL;
    ListNode *toReturn = root;
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->val <= l2->val)
        {
            root->next = l1;
            root = l1;
            l1 = l1->next;
        }
        else
        {
            root->next = l2;
            root = l2;
            l2 = l2->next;
        }
        root->next = NULL;
    }
    if (l1 != NULL)
        root->next = l1;
    if (l2 != NULL)
        root->next = l2;
    return toReturn;
}