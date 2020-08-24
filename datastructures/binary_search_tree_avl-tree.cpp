#include <iostream>
using namespace std;

class Node{
public:
	int data;
	int height;
	Node* left;
	Node* right;
public:
	Node(){
		left=NULL;
		right=NULL;
		height=0;
	}
	Node(int d){
		left=NULL;
		right=NULL;
		height=0;
		data=d;
	}
};

//retrieve height of a node
int height(Node* node){
	if(node==NULL)
		return -1;
	return node->height;
}

//get maximum  number
int maxof(int a, int b){
	return a>b?a:b;
}

//get balance factor of any node
int balance(Node* node){
	if(node==NULL)
		return 0;
	return height(node->left)-height(node->right);
}

Node* rightrotate(Node*);
Node* leftrotate(Node*);

//insert a node
Node* insert(Node* node, int data){
	Node* temp=new Node(data);
	if(node==NULL){
		return temp;
	}
	if(data<=node->data){
		node->left = insert(node->left, data);
	}
	else{
		node->right = insert(node->right, data);
	}
	//update height of this node
	node->height = 1+maxof(height(node->left), height(node->right));
	/*Get the balance factor of this ancestor  
      node to check whether this node became  
      unbalanced */
	int balance_factor=balance(node);
	//left left case
	if(balance_factor>1 && data<=node->left->data){
		return rightrotate(node);
	}
	//right right case
	if(balance_factor<-1 && data>node->right->data){
		return leftrotate(node);
	}
	//left right case
	if(balance_factor>1 && data>node->left->data){
		node->left = leftrotate(node->left);
		return rightrotate(node);
	}
	//right left case
	if(balance_factor<-1 && data<=node->right->data){
		node->right = rightrotate(node->right);
		return leftrotate(node);
	}
	return node;
}

int height_of(Node* node){
	if(node==NULL)
		return -1;
	return 1+maxof(height_of(node->left), height_of(node->right));
}

Node* smallestElementOf(Node* node){
	while(node->left!=NULL){
		node = node->left;
	}
	return node;
}

Node* deleteNode(Node* node, int data){
	if(node==NULL){
		return node;
	}
	if(data<node->data){
		node->left=deleteNode(node->left, data);
	}
	else if(data>node->data){
		node->right=deleteNode(node->right, data);
	}
	else{
		if(node->left==NULL || node->right==NULL){
			if(node->left==NULL){
				Node* temp = node;
				node = node->right;
				delete temp;
				return node;
			}
			Node* temp = node;
			node = node->left;
			delete temp;
			return node;
		}
		Node* temp = smallestElementOf(node->right); //inorder successor
		node->data = temp->data;
		deleteNode(node->right, temp->data);
	}
	//update height
	node->height = 1+maxof(height(node->left), height(node->right));
	//get balance factor
	int k = balance(node);
	//four cases
	//left left //k>1 means left of node is heavy & balance(node->left)>=0 means left of node->left
	            //    is heavy. Hence left left is correct option
	if(k>1 && balance(node->left)>=0)
		return rightrotate(node);
	//left right
	if(k>1 && balance(node->left)<0){
		node->left = leftrotate(node->left);
		return rightrotate(node);
	}
	//right right
	if(k<-1 && balance(node->right)>=0){
		return leftrotate(node);
	}
	//right left
	if(k<-1 && balance(node->right)<0){
		node->right = rightrotate(node->right);
		return leftrotate(node);
	}
	return node;
}

int main(){
	Node* root=NULL;
	cout<<"Insertion:\n";
	root=insert(root, 9);
	cout<<height_of(root->left)-height_of(root->right)<<endl;
	root=insert(root, 8);
	cout<<height_of(root->left)-height_of(root->right)<<endl;
	root=insert(root, 7);
	cout<<height_of(root->left)-height_of(root->right)<<endl;
	root=insert(root, 6);
	cout<<height_of(root->left)-height_of(root->right)<<endl;
	root=insert(root, 5);
	cout<<height_of(root->left)-height_of(root->right)<<endl;
	root=insert(root, 4);
	cout<<height_of(root->left)-height_of(root->right)<<endl;
	root=insert(root, 3);
	cout<<height_of(root->left)-height_of(root->right)<<endl;
	root=insert(root, 2);
	cout<<height_of(root->left)-height_of(root->right)<<endl;
	root=insert(root, 1);
	cout<<height_of(root->left)-height_of(root->right)<<endl;
	cout<<"Deletion:\n";
	root=deleteNode(root, 9);
	cout<<height_of(root->left)-height_of(root->right)<<endl;
	root=deleteNode(root, 8);
	cout<<height_of(root->left)-height_of(root->right)<<endl;
	root=deleteNode(root, 7);
	cout<<height_of(root->left)-height_of(root->right)<<endl;
	root=deleteNode(root, 6);
	cout<<height_of(root->left)-height_of(root->right)<<endl;
	root=deleteNode(root, 5);
	cout<<height_of(root->left)-height_of(root->right)<<endl;
	root=deleteNode(root, 4);
	cout<<height_of(root->left)-height_of(root->right)<<endl;
	root=deleteNode(root, 3);
	cout<<height_of(root->left)-height_of(root->right)<<endl;
	root=deleteNode(root, 2);
	cout<<height_of(root->left)-height_of(root->right)<<endl;
	root=deleteNode(root, 1);
	cout<<height_of(root->left)-height_of(root->right)<<endl;
    return 0;
}

Node* rightrotate(Node* node){
	Node* x=node->left;
	Node* y=x->right;
	//rotation
	x->right=node;
	node->left=y;
	//update heights
	node->height=1+maxof(height(node->left), height(node->right));
	x->height = 1+maxof(height(x->left), height(x->right));
	//return new node
	return x;
}

Node* leftrotate(Node* node){
	Node* x=node->right;
	Node* y=x->left;
	//rotation
	x->left=node;
	node->right=y;
	//update heights
	node->height=1+maxof(height(node->left), height(node->right));
	x->height = 1+maxof(height(x->left), height(x->right));
	//return new node
	return x;
}