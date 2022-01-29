#include <bits/stdc++.h>
using namespace std;

// Balanced Binary Tree
// https://leetcode.com/problems/balanced-binary-tree/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

int solve(TreeNode *root)
{
    if (!root)
        return 0;
    int l = solve(root->left);
    if (l == -1)
        return -1;
    int r = solve(root->right);
    if (r == -1)
        return -1;
    if (abs(l - r) > 1)
        return -1;
    return 1 + max(l, r);
}
bool isBalanced(TreeNode *root)
{
    return solve(root) != -1;
}