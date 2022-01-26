#include <bits/stdc++.h>
using namespace std;

// Top View of Binary Tree
// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1#
// Level order travel used

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

vector<int> topView(Node *root)
{
    vector<int> res;
    if (!root)
        return res;
    map<int, int> mp;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        Node *temp = q.front().first;
        int d = q.front().second;
        q.pop();
        if (mp.find(d) == mp.end())
            mp[d] = temp->data;
        if (temp->left)
            q.push({temp->left, d - 1});
        if (temp->right)
            q.push({temp->right, d + 1});
    }
    for (auto it : mp)
        res.push_back(it.second);
    return res;
}