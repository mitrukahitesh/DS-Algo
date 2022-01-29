#include <bits/stdc++.h>
using namespace std;

// Same Tree
// https://leetcode.com/problems/same-tree/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == NULL ^ q == NULL)
        return false;
    if (p == NULL && q == NULL)
        return true;
    if (p->val != q->val)
        return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

// OR

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == NULL || q == NULL)
        return p == q;
    return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}