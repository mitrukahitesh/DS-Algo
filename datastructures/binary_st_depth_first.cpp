#include <iostream>
#include <queue>

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

// bool find(node* root, int x){
// 	if(root==NULL){
// 		return false;
// 	}
// 	if(root->data==x){
// 		return true;
// 	}
// 	else if(x<=root->data){
// 		return find(root->left, x);
// 	}
// 	else{
// 		return find(root->right, x);
// 	}
// }

// int find_min(node* root){
// 	if(root==NULL){
// 		cout<<"Empty tree";
// 		return -1;
// 	}
// 	if(root->left==NULL){
// 		return root->data;
// 	}
// 	return find_min(root->left);
// }

// int find_max(node* root){
// 	if(root==NULL){
// 		cout<<"Empty tree";
// 		return -1;
// 	}
// 	if(root->right==NULL){
// 		return root->data;
// 	}
// 	return find_max(root->right);
// }

// int max_of(int a, int b){
// 	if(a>b)
// 		return a;
// 	return b;
// }

// int height(node* root){
// 	if(root==0){
// 		return -1;
// 	}
// 	return 1+max_of(height(root->left), height(root->right));
// }

void level_order_traversal(node* root) {
    queue<node*> discovered;
    node* visit;
    discovered.push(root);
    if (root != NULL) {
        while (!discovered.empty()) {
            visit = discovered.front();
            discovered.pop();
            cout << visit->data << " ";
            if (visit->left != NULL) discovered.push(visit->left);
            if (visit->right != NULL) discovered.push(visit->right);
        }
        cout << "\n";
    } else {
        cout << "\n";
    }
}

void preorder_traversal(node* root) {
    if (root == NULL) {
        return;
    }
    node* temp = root;
    cout << temp->data << " ";
    preorder_traversal(temp->left);
    preorder_traversal(temp->right);
}

void inorder_traversal(node* root) {
    if (root == NULL) return;
    node* temp = root;  // root can be used instead of temp as root is just a
                        // copy of root in main
    inorder_traversal(temp->left);
    cout << temp->data << " ";
    inorder_traversal(temp->right);
}

void postorder_traversal(node* root) {
    if (root == NULL) return;
    node* temp = root;
    postorder_traversal(temp->right);
    postorder_traversal(temp->left);
    cout << temp->data << " ";
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
    // if(find(root,7))
    // 	cout<<"Found\n";
    // else
    // 	cout<<"Not found\n";
    // if(find(root,11))
    // 	cout<<"Found\n";
    // else
    // 	cout<<"Not found\n";
    // cout<<find_min(root)<<endl;
    // cout<<find_max(root)<<endl;
    // cout<<"Height of tree= "<<height(root)<<endl;
    level_order_traversal(root);
    preorder_traversal(root);
    cout << endl;
    inorder_traversal(root);
    cout << endl;
    postorder_traversal(root);
    return 0;
}