#include <bits/stdc++.h>
using namespace std;

// Diameter of tree
// O(n) time

class TreeNode
{
public:
    TreeNode *left, *right;
};

int diameter(TreeNode *root, int &res)
{
    if (root == NULL)
        return -1;
    int l = diameter(root->left, res);
    int r = diameter(root->right, res);
    int height = 1 + max(l, r);
    res = max(res, 2 + l + r);
    return height;
}
int diameterOfBinaryTree(TreeNode *root)
{
    int res = -1;
    diameter(root, res);
    return res;
}