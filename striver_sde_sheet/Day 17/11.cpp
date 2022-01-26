#include <bits/stdc++.h>
using namespace std;

// Print Root to Node Path in Binary Tree
// https://www.interviewbit.com/problems/path-to-given-node/

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool solve(TreeNode *root, int t, vector<int> &res)
{
    if (root == NULL)
        return false;
    res.push_back(root->val);
    if (root->val == t)
    {
        return true;
    }
    if (solve(root->left, t, res) || solve(root->right, t, res))
    {
        return true;
    }
    res.pop_back();
    return false;
}

vector<int> findPath(TreeNode *A, int B)
{
    vector<int> res;
    solve(A, B, res);
    return res;
}