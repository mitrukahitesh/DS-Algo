#include <iostream>
#include<bits/stdc++.h>

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

bool isBST(node* root, int min=INT_MIN, int max=INT_MAX){
	if(root==NULL)
		return true;
	if((root->data>min && root->data<=max) && isBST(root->left, min, root->data) && isBST(root->right, root->data, max))
		return true;
	else
		return false;
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
	//root->left->data=8;  //not BST if this line is included
	if(isBST(root))
		cout<<"B S T\n";
	else
		cout<<"Not a B S T\n";
	return 0;
}