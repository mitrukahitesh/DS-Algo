#include <bits/stdc++.h>
using namespace std;

// Binary Tree Zigzag Level Order Traversal
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> res;
    if (!root)
        return res;
    bool rev = false;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        vector<int> v(n);
        for (int i = 0; i < n; ++i)
        {
            TreeNode *temp = q.front();
            q.pop();
            int x = rev ? n - i - 1 : i;
            v[x] = temp->val;
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        res.push_back(v);
        rev = !rev;
    }
    return res;
}