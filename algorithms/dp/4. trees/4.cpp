#include <bits/stdc++.h>
using namespace std;

// Maximum Path sum | From leaf node to leaf node

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

int solve(Node *root, int &res)
{
    if (root == NULL)
        return 0;
    int l = solve(root->left, res);
    int r = solve(root->right, res);
    if (root->left == NULL)
        return root->data + r;
    if (root->right == NULL)
        return root->data + l;
    res = max(res, root->data + l + r);
    return root->data + max(l, r);
}
int maxPathSum(Node *root)
{
    int res = INT_MIN;
    int x = solve(root, res);
    return res == INT_MIN ? x : res;
}