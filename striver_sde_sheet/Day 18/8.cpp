#include <bits/stdc++.h>
using namespace std;

// Boundary Traversal
// https://www.codingninjas.com/codestudio/problems/boundary-traversal_790725?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;
};

void getLeft(TreeNode<int> *root, vector<int> &res)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;
    res.push_back(root->data);
    if (root->left == NULL)
        getLeft(root->right, res);
    else
        getLeft(root->left, res);
}

void getLeaves(TreeNode<int> *root, vector<int> &res)
{
    if (root == NULL)
        return;
    getLeaves(root->left, res);
    if (root->left == NULL && root->right == NULL)
        res.push_back(root->data);
    getLeaves(root->right, res);
}

void getRight(TreeNode<int> *root, vector<int> &res)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;
    if (root->right == NULL)
        getRight(root->left, res);
    else
        getRight(root->right, res);
    res.push_back(root->data);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
    vector<int> res;
    if (root == NULL)
        return res;
    res.push_back(root->data);
    getLeft(root->left, res);
    getLeaves(root->left, res);
    getLeaves(root->right, res);
    getRight(root->right, res);
    return res;
}