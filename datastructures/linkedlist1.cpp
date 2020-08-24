#include <iostream>

using namespace std;


struct node{
	int data;
	node* next;
};

node* head;

void insert(int val, int pos){
	node* temp = new node;
	if(pos==0){
		temp->data=val;
		temp->next=head;
		head=temp;
	}
	else{
		node* temp1 = new node;
		temp=head;
		if(temp==NULL && pos!=0){
				cout<<"Invalid position..\n";
				return;
			}
		int i;
		for(i=0; i<pos-1; i++){
			temp=temp->next;
			if(temp==NULL && i<pos-2){
				cout<<"Invalid position..\n";
				return;
		}
		}
		temp1->data=val;
		temp1->next=temp->next;
		temp->next=temp1;
	}
}

void print(){
	node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}

void dlt_val(int pos){
	if(pos==0){
		if(head==NULL){
			cout<<"Invalid position...\n";
			return;
		}
		else{
			node* temp1 = new node;
			temp1 = head;
			head = temp1->next;
			delete temp1;
		}
	}
	else{
		node* temp1 = new node;
		temp1 = head;
		if(head==NULL){
			cout<<"Invalid position...\n";
			return;
		}
		int i;
		for(i=0; i<pos-1; i++){
			temp1 = temp1->next;
			if(temp1==NULL && i<pos-2){
				cout<<"Invalid position...\n";
				return;
			}
		}
		node* temp = temp1->next;
		temp1->next=temp->next;
		delete temp;
	}
}

int main(){
	head = NULL;

	insert(0,0);  //0
	print();
	cout<<"\n";

	insert(1,1);  //0 1
	print();
	cout<<"\n";

	insert(2,2);  //0 1 2
	print();
	cout<<"\n";

	insert(4,3);  //0 1 2 4 
	print();
	cout<<"\n";

	insert(5,4);  //0 1 2 4 5
	print();
	cout<<"\n";

	insert(6,5);  //0 1 2 4 5 6
	print();
	cout<<"\n";

	insert(3,3);  //0 1 2 3 4 5 6 
	print();
	cout<<"\n";

	insert(-1,0);  //-1 0 1 2 3 4 5 6 
	print();
	cout<<"\n";

	dlt_val(0);    //0 1 2 3 4 5 6
	print();
	cout<<"\n";

	dlt_val(3);	   //0 1 2 4 5 6
	print();
	cout<<"\n";

	dlt_val(5);    //0 1 2 4 5
	print();
	cout<<"\n";


	return 0;
}