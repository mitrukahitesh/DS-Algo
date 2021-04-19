#include <iostream>

using namespace std;

class node {
   public:
    int data;
    node* left;
    node* right;
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

bool islesser(node* root, int data) {
    if (root == NULL) return true;
    if (root->data <= data && islesser(root->left, data) &&
        islesser(root->right, data))
        return true;
    else
        return false;
}

bool isgreater(node* root, int data) {
    if (root == NULL) return true;
    if (root->data > data && isgreater(root->left, data) &&
        isgreater(root->right, data))
        return true;
    else
        return false;
}

bool isBST(node* root) {
    if (root == NULL) return true;
    if (islesser(root->left, root->data) &&
        isgreater(root->right, root->data) && isBST(root->left) &&
        isBST(root->right))
        return true;
    return false;
}

int main() {
    node* root = NULL;
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 7);
    root = insert(root, 1);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 8);
    // root->left->data=8;  //not BST is this line is included
    if (isBST(root))
        cout << "B S T\n";
    else
        cout << "Not a B S T\n";
    return 0;
}