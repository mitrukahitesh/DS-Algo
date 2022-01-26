#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=ySp2epYvgTE
// Preorder Inorder Postorder Traversals in One Traversal
// https://bit.ly/3rlXpTX
// O(3n) time and O(4n) space

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)
{
    vector<vector<int>> res(3);
    if (!root)
        return res;
    stack<pair<BinaryTreeNode<int> *, int>> s;
    s.push({root, 0});
    while (!s.empty())
    {
        BinaryTreeNode<int> *temp = s.top().first;
        int n = s.top().second;
        s.pop();
        if (n + 1 < 3)
        {
            s.push({temp, n + 1});
        }
        res[n].push_back(temp->data);
        if (n == 0)
        {
            if (temp->left)
            {
                s.push({temp->left, 0});
            }
        }
        else if (n == 1)
        {
            if (temp->right)
            {
                s.push({temp->right, 0});
            }
        }
    }
    swap(res[0], res[1]);
    return res;
}