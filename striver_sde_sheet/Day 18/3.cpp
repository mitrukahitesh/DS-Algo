#include <bits/stdc++.h>
using namespace std;

// Diameter of Binary Tree
// https://leetcode.com/problems/diameter-of-binary-tree/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

int diameter(TreeNode *root, int &res)
{
    if (!root)
        return 0;
    int l = diameter(root->left, res);
    int r = diameter(root->right, res);
    res = max(res, l + r);
    return 1 + max(l, r);
}

int diameterOfBinaryTree(TreeNode *root)
{
    int res = 0;
    diameter(root, res);
    return res;
}