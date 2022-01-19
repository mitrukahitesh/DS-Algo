#include <bits/stdc++.h>
using namespace std;

// General Syntax

class Node
{
public:
    Node *left, *right;
};

int solve(Node *root, int &res)
{
    //Base condition
    if (root == NULL)
        return 0;
    // Hypothesis
    int l = solve(root->left, res);
    int r = solve(root->right, res);
    // Induction
    int temp = 1 + max(l, r);
    int ans;
    // ans = max(temp, RELATION);
    res = max(res, ans);
    return temp;
}