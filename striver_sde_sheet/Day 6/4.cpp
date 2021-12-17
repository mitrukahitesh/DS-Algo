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
    Naive: Traverse and create array, then check for palindrome
    O(2n) time
    O(n) space

    Optimized:
        Find middle of linked list (take first node if even numbered ll)
        Reverse second half of ll
        Then compare first and second half
    O(n/2 + n/2 + n/2) time
    O(1) space
*/

// Naive
bool isPalindrome(ListNode *head)
{
    vector<int> vec;
    while (head != NULL)
    {
        vec.push_back(head->val);
        head = head->next;
    }
    int l = 0, h = vec.size() - 1;
    while (l < h)
    {
        if (vec[l] != vec[h])
            return false;
        l++;
        h--;
    }
    return true;
}

// Optimized
ListNode *middleNode2(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode *reverseList(ListNode *head)
{
    if (!head)
        return NULL;
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *next;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(ListNode *head)
{
    ListNode *middle = middleNode2(head);
    middle->next = reverseList(middle->next);
    middle = middle->next;
    while (middle != NULL && head->val == middle->val)
    {
        head = head->next;
        middle = middle->next;
    }
    return middle == NULL;
}