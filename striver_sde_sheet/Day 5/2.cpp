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
    Count the number of nodes then traverse to mid node
    O(n) + O(n / 2) time
    O(1) space

    Optimize solution:
    Tortoise & Hare method
    O(n / 2) time
    O(1) space
*/

// Brute force
ListNode *middleNode1(ListNode *head)
{
    int count = 0;
    ListNode *temp = head;
    while (temp)
    {
        ++count;
        temp = temp->next;
    }
    count /= 2;
    temp = head;
    while (count--)
    {
        temp = temp->next;
    }
    return temp;
}

// Tortoise & Hare method
ListNode *middleNode2(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}