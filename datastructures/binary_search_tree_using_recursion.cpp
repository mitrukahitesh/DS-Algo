#include <iostream>

using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;
	node(int x){
		data=x;
		left=NULL;
		right=NULL;
	}
};

node* insert(node* root, int x){
	if(root==NULL){
		node* newNode=new node(x);
		root = newNode;
	}
	else if(x<=root->data){
		root->left=insert(root->left,x);
	}
	else{
		root->right=insert(root->right,x);
	}
	return root;
}

bool find(node* root, int x){
	if(root==NULL){
		return false;
	}
	if(root->data==x){
		return true;
	}
	else if(x<=root->data){
		return find(root->left, x);
	}
	else{
		return find(root->right, x);
	}
}

int find_min(node* root){
	if(root==NULL){
		cout<<"Empty tree";
		return -1;
	}
	if(root->left==NULL){
		return root->data;
	}
	return find_min(root->left);
}

int find_max(node* root){
	if(root==NULL){
		cout<<"Empty tree";
		return -1;
	}
	if(root->right==NULL){
		return root->data;
	}
	return find_max(root->right);
}

int max_of(int a, int b){
	if(a>b)
		return a;
	return b;
}

int height(node* root){
	if(root==0){
		return -1;
	}
	return 1+max_of(height(root->left), height(root->right));
}

int main(){
	node* root=NULL;
	root=insert(root,4);
	root=insert(root,2);
	root=insert(root,7);
	root=insert(root,1);
	root=insert(root,5);
	root=insert(root,6);
	root=insert(root,8);
	if(find(root,7))
		cout<<"Found\n";
	else
		cout<<"Not found\n";
	if(find(root,11))
		cout<<"Found\n";
	else
		cout<<"Not found\n";
	cout<<find_min(root)<<endl;
	cout<<find_max(root)<<endl;
	cout<<"Height of tree= "<<height(root)<<endl;
	return 0;
}