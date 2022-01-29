#include <bits/stdc++.h>
using namespace std;

// LCA
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

/*
    Brute force: Find parents of both node and return last common parent
    O(2n) time and space
    Optimal: O(n) extra time and space is reduced
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

// Optimal
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    //base case
    if (root == NULL || root == p || root == q)
    {
        return root;
    }
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);

    //result
    if (left == NULL)
    {
        return right;
    }
    else if (right == NULL)
    {
        return left;
    }
    else
    { //both left and right are not null, we found our result
        return root;
    }
}