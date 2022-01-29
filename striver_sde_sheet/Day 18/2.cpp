#include <bits/stdc++.h>
using namespace std;

// Maximum Depth of Binary Tree
// https://leetcode.com/problems/maximum-depth-of-binary-tree/

// O(N) time and space

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

int maxDepth(TreeNode *root)
{
    if (!root)
        return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}
