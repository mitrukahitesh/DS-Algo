#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

/*
    Brute force:
        Create hashmap <Node, Node> that stores new Node corresponding to every node
        Create corresponding new nodes
        Then traverse and set nexand random
    O(n) + O(n) time
    O(n) space

    Optimal:
        1. Create copy nodes and insert right after original node
            1->2->3->4 ==> 1->1*->2->2*->3->3*->4->4*
        2. Point random pointers
            iter.next.random = iter.random.next
            iter = iter.next.next
        3. Separate deep copy list and original list
    O(n) + O(n) + O(n) time
    O(1) space
*/

Node *copyRandomList(Node *head)
{
    if (!head)
        return head;
    Node *temp = head;

    // 1
    while (temp != NULL)
    {
        Node *x = new Node(temp->val);
        x->next = temp->next;
        temp->next = x;
        temp = x->next;
    }
    temp = head;

    // 2
    while (temp != NULL)
    {
        temp->next->random = temp->random == NULL ? NULL : temp->random->next;
        temp = temp->next->next;
    }
    temp = head->next;

    // 3
    Node *res = head->next;
    Node *x = head;
    Node *y = head->next->next;
    while (y != NULL)
    {
        x->next = y;
        temp->next = y->next;
        temp = y->next;
        x = y;
        y = y->next->next;
    }
    x->next = NULL;

    return res;
}