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

node* delete_node(node* root, int data){
	if(root==NULL)
		return root;
	node* temp=root;
	node* previous;
	while(temp->data!=data){
		previous=temp;
		if(data<=temp->data)
			temp=temp->left;
		else
			temp=temp->right;
	}
	if(temp->left==NULL && temp->right==NULL){
		if(temp->data>previous->data)
			previous->right=NULL;
		else
			previous->left=NULL;
		delete temp;
		return root;
	}
	else if(temp->left==NULL || temp->right==NULL){
		if(temp->left==NULL){
			if(data<=previous->data){
				previous->left=temp->right;
				delete temp;
				return root;
			}
			else{
				previous->right=temp->right;
				delete temp;
				return root;
			}
		}
		else{
			if(data<=previous->data){
				previous->left=temp->left;
				delete temp;
				return root;
			}
			else{
				previous->right=temp->left;
				delete temp;
				return root;
			}
		}
	}
	else{
		node* _temp=temp;
		while(_temp->left!=NULL){
			previous=_temp;
			_temp=_temp->left;
		}
		temp->data=_temp->data;
		if(_temp->right==NULL){
			previous->left==NULL;
			delete _temp;
			return root;
		}
		previous->left=_temp->right;
		delete _temp;
		return root;
	}
	return root;
}

void depth_first_traversal(node* root){
	queue<node*> q;
	if(root==NULL)
		return;
	q.push(root);
	while(!q.empty()){
		node* temp=q.front();
		q.pop();
		if(temp->left!=NULL)
		q.push(temp->left);
		cout<<temp->data<<" ";
		if(temp->right!=NULL)
		q.push(temp->right);
	}
	cout<<"\n";
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
	depth_first_traversal(root);
	delete_node(root, 7);
	depth_first_traversal(root);
	return 0;
}