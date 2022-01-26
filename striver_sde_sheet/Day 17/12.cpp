#include <bits/stdc++.h>
using namespace std;

// Maximum Width of Binary Tree
// https://leetcode.com/problems/maximum-width-of-binary-tree/

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/*
    If i the node number, then it's left child will
    have node number 2*i+1 and right will have 2*i+2
    for 0 based indexing.
    2*i & 2*i+1 for 1 based
*/

// My approach -> int overflow issue solved by taking unsigned long long
#define ll unsigned long long
int widthOfBinaryTree(TreeNode *root)
{
    ll width = 0;
    if (!root)
        return 0;
    // node, level, node_number
    queue<pair<TreeNode *, pair<ll, ll>>> q;
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        ll level = q.front().second.first;
        ll d1 = q.front().second.second;
        while (!q.empty() && q.front().second.first == level)
        {
            TreeNode *temp = q.front().first;
            ll d2 = q.front().second.second;
            q.pop();
            width = max(width, d2 - d1 + 1);
            if (temp->left)
            {
                q.push({temp->left, {level + 1, 2 * d2 + 1}});
            }
            if (temp->right)
            {
                q.push({temp->right, {level + 1, 2 * d2 + 2}});
            }
        }
    }
    return width;
}

// Optimal
int widthOfBinaryTree(TreeNode *root)
{
    int width = 0;
    if (!root)
        return 0;
    // node, node_number
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        int mmin = q.front().second;
        int size = q.size();
        for (int i = 0; i < size; ++i)
        {
            TreeNode *temp = q.front().first;
            int x = q.front().second - mmin;
            q.pop();
            width = max(width, x + 1);
            if (temp->left)
            {
                q.push({temp->left, 2 * x + 1});
            }
            if (temp->right)
            {
                q.push({temp->right, 2 * x + 2});
            }
        }
    }
    return width;
}