#include <bits/stdc++.h>
using namespace std;

// Vertical Order Traversal of a Binary Tree
// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    vector<vector<int>> res;
    if (!root)
        return res;
    // distance, level, elements
    map<int, map<int, multiset<int>>> mp;
    // node, level, distance
    queue<pair<TreeNode *, pair<int, int>>> q;
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        TreeNode *temp = q.front().first;
        int level = q.front().second.first;
        int d = q.front().second.second;
        q.pop();
        mp[d][level].insert(temp->val);
        if (temp->left)
        {
            q.push({temp->left, {level + 1, d - 1}});
        }
        if (temp->right)
        {
            q.push({temp->right, {level + 1, d + 1}});
        }
    }
    for (auto d : mp)
    {
        vector<int> v;
        for (auto l : d.second)
        {
            v.insert(v.end(), l.second.begin(), l.second.end());
        }
        res.push_back(v);
    }
    return res;
}