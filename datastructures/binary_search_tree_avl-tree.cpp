#include <iostream>
using namespace std;

class Node {
   public:
    int data;
    Node* left;
    Node* right;
    int ht;
    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
        ht = 0;
    }
};

int maxOf(int a, int b) { return (a > b ? a : b); }
int heightOf(Node* node) {
    if (node == NULL) return -1;
    return node->ht;
}

Node* rightRotate(Node* node) {
    Node* toReturn = node->left;
    Node* leftRight = toReturn->right;
    toReturn->right = node;
    node->left = leftRight;
    node->ht = 1 + maxOf(heightOf(node->left), heightOf(node->right));
    toReturn->ht =
        1 + maxOf(heightOf(toReturn->left), heightOf(toReturn->right));
    return toReturn;
}
Node* leftRotate(Node* node) {
    Node* toReturn = node->right;
    Node* rightLeft = toReturn->left;
    toReturn->left = node;
    node->right = rightLeft;
    node->ht = 1 + maxOf(heightOf(node->left), heightOf(node->right));
    toReturn->ht =
        1 + maxOf(heightOf(toReturn->left), heightOf(toReturn->right));
    return toReturn;
}

Node* insert(Node* root, int data) {
    if (root == NULL) {
        return new Node(data);
    }
    if (data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    root->ht = 1 + maxOf(heightOf(root->left), heightOf(root->right));
    int k = heightOf(root->left) - heightOf(root->right);
    if (k > 1) {
        if (data <= root->left->data) {
            return rightRotate(root);
        } else {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    } else if (k < -1) {
        if (data > root->right->data) {
            return leftRotate(root);
        } else {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }
    return root;
}

int getInOrderSuccessor(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}
int getBalance(Node* root) {
    return heightOf(root->left) - heightOf(root->right);
}

Node* deleteNode(Node* root, int data) {
    if (root == NULL) return NULL;
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL || root->right == NULL) {
            Node* temp = (root->left ? root->left : root->right);
            delete root;
            return temp;
        }
        int inOrder = getInOrderSuccessor(root->right);
        root->data = inOrder;
        root->right = deleteNode(root->right, inOrder);
    }
    root->ht = 1 + maxOf(heightOf(root->left), heightOf(root->right));
    int k = heightOf(root->left) - heightOf(root->right);
    if (k > 1) {
        if (getBalance(root->left) >= 0) {
            return rightRotate(root);
        } else {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    } else if (k < -1) {
        if (getBalance(root->right) > 0) {
            return leftRotate(root);
        } else {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }
    return root;
}

int main() {
    Node* root = NULL;
    cout << "Insertion:\n";
    root = insert(root, 9);
    cout << heightOf(root->left) - heightOf(root->right) << endl;
    root = insert(root, 8);
    cout << heightOf(root->left) - heightOf(root->right) << endl;
    root = insert(root, 7);
    cout << heightOf(root->left) - heightOf(root->right) << endl;
    root = insert(root, 6);
    cout << heightOf(root->left) - heightOf(root->right) << endl;
    root = insert(root, 5);
    cout << heightOf(root->left) - heightOf(root->right) << endl;
    root = insert(root, 4);
    cout << heightOf(root->left) - heightOf(root->right) << endl;
    root = insert(root, 3);
    cout << heightOf(root->left) - heightOf(root->right) << endl;
    root = insert(root, 2);
    cout << heightOf(root->left) - heightOf(root->right) << endl;
    root = insert(root, 1);
    cout << heightOf(root->left) - heightOf(root->right) << endl;
    cout << "Deletion:\n";
    root = deleteNode(root, 9);
    cout << heightOf(root->left) - heightOf(root->right) << endl;
    root = deleteNode(root, 8);
    cout << heightOf(root->left) - heightOf(root->right) << endl;
    root = deleteNode(root, 7);
    cout << heightOf(root->left) - heightOf(root->right) << endl;
    root = deleteNode(root, 6);
    cout << heightOf(root->left) - heightOf(root->right) << endl;
    root = deleteNode(root, 5);
    cout << heightOf(root->left) - heightOf(root->right) << endl;
    root = deleteNode(root, 4);
    cout << heightOf(root->left) - heightOf(root->right) << endl;
    root = deleteNode(root, 3);
    cout << heightOf(root->left) - heightOf(root->right) << endl;
    root = deleteNode(root, 2);
    cout << heightOf(root->left) - heightOf(root->right) << endl;
    root = deleteNode(root, 1);
    return 0;
}