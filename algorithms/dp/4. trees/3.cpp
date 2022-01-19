#include <bits/stdc++.h>
using namespace std;

// Maximum Path Sum | From any Node to any Node

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
};

int solve(TreeNode *root, int &res)
{
    if (root == NULL)
        return 0;
    int l = max(solve(root->left, res), 0);
    int r = max(solve(root->right, res), 0);
    res = max(res, root->val + l + r);
    return root->val + max(l, r);
}
int maxPathSum(TreeNode *root)
{
    int res = INT_MIN;
    solve(root, res);
    return res;
}