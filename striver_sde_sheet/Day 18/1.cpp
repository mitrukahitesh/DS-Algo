#include <bits/stdc++.h>
using namespace std;

// Binary Tree Level Order Traversal
// https://leetcode.com/problems/binary-tree-level-order-traversal/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> res;
    if (!root)
        return res;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        vector<int> v;
        for (int i = 0; i < n; ++i)
        {
            TreeNode *temp = q.front();
            q.pop();
            v.push_back(temp->val);
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        res.push_back(v);
    }
    return res;
}

// Spiral -> 7.cpp