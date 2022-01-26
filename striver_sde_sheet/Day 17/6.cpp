#include <bits/stdc++.h>
using namespace std;

// Right View of Binary Tree (same as left view)
// https://leetcode.com/problems/binary-tree-right-side-view/

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void rightView(TreeNode *root, vector<int> &res, int ht, int &mx)
{
    if (root == NULL)
        return;
    if (ht > mx)
    {
        res.push_back(root->val);
        mx = ht;
    }
    rightView(root->right, res, ht + 1, mx);
    rightView(root->left, res, ht + 1, mx);
}
vector<int> rightSideView(TreeNode *root)
{
    vector<int> res;
    int mx = -1;
    rightView(root, res, 0, mx);
    return res;
}