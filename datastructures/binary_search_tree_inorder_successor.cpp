#include <bits/stdc++.h>

using namespace std;

class node {
   public:
    int data;
    node* left;
    node* right;
    // node* parent;
    node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

node* insert(node* root, int x) {
    if (root == NULL) {
        node* newNode = new node(x);
        root = newNode;
    } else if (x <= root->data) {
        root->left = insert(root->left, x);
    } else {
        root->right = insert(root->right, x);
    }
    return root;
}

int inorder_successor(node* root, int data) {
    node* pos_data = root;
    if (root == NULL) {
        cout << "empty tree";
        return -1;
    }
    while (pos_data->data != data) {
        if (pos_data->data >= data)
            pos_data = pos_data->left;
        else
            pos_data = pos_data->right;
        if (pos_data == NULL) break;
    }
    if (pos_data == NULL) {
        cout << "invalid data";
        return -1;
    }
    if (pos_data->right != NULL) {  // right sub-tree
        node* successor = pos_data->right;
        while (successor->left != NULL) successor = successor->left;
        return successor->data;
    } else {  // no right sub-tree
        node* successor = NULL;
        node* ancestor = root;
        while (ancestor != pos_data) {
            if (pos_data->data <= ancestor->data) {
                successor = ancestor;  // so far this is the deepest node for
                                       // which pos_data is in left
                ancestor = ancestor->left;
            } else
                ancestor = ancestor->right;
        }
        if (successor == NULL) cout << "no successor";
        return successor->data;
    }
}

int main() {
    node* root = NULL;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 14);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 13);
    cout << inorder_successor(root, 20) << endl;
    return 0;
}