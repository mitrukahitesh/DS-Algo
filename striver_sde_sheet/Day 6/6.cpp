#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

Node *merge(Node *l1, Node *l2)
{
    Node *temp, *res;
    temp = new Node(0);
    res = temp;
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->data < l2->data)
        {
            temp->bottom = l1;
            l1 = l1->bottom;
        }
        else
        {
            temp->bottom = l2;
            l2 = l2->bottom;
        }
        temp = temp->bottom;
    }
    if (l1 != NULL)
        temp->bottom = l1;
    else if (l2 != NULL)
        temp->bottom = l2;
    return res->bottom;
}

Node *flatten_list(Node *l1)
{
    if (l1->next == NULL)
        return l1;
    Node *l2 = flatten_list(l1->next);
    return merge(l1, l2);
}

// O(Total number of nodes) time
// O(1) space
// Recursively merge last 2 lists
Node *flatten(Node *root)
{
    return flatten_list(root);
}