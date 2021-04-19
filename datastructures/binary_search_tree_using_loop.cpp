#include <iostream>

using namespace std;

class node {
   private:
    node* root;
    int data;
    node* left;
    node* right;

   public:
    node() {
        root = NULL;
        left = NULL;
        right = NULL;
    }
    node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
    void insert(int x) {
        node* newNode = new node(x);
        if (root == NULL) {
            root = newNode;
            return;
        }
        node* temp = root;
        node* temp_previous;
        while (temp != NULL) {
            temp_previous = temp;
            if (x <= temp->data)
                temp = temp->left;
            else
                temp = temp->right;
        }
        if (x > temp_previous->data)
            temp_previous->right = newNode;
        else
            temp_previous->left = newNode;
    }
    bool find(int x) {
        node* temp = root;
        while (temp != NULL) {
            if (temp->data == x) return true;
            if (x <= temp->data)
                temp = temp->left;
            else
                temp = temp->right;
        }
        return false;
    }

    int min() {
        node* temp = root;
        if (root == NULL) {
            cout << "Empty tree";
            return -1;
        }
        while (temp->left != NULL) {
            temp = temp->left;
        }
        return temp->data;
    }

    int max() {
        node* temp = root;
        if (root == NULL) {
            cout << "Empty tree";
            return -1;
        }
        while (temp->right != NULL) {
            temp = temp->right;
        }
        return temp->data;
    }
    int height() {
        cout << "Coming soon" << endl;
        return -1;
    }
};

int main() {
    node tree;
    tree.insert(1);
    tree.insert(4);
    tree.insert(7);
    tree.insert(2);
    tree.insert(5);
    tree.insert(6);
    tree.insert(8);
    if (tree.find(7))
        cout << "Found 7\n";
    else
        cout << "7 Not Found\n";
    if (tree.find(11))
        cout << "Found 11\n";
    else
        cout << "11 Not Found\n";
    cout << tree.min() << endl;
    cout << tree.max() << endl;
    cout << "Height of tree: " << tree.height() << endl;
    return 0;
}